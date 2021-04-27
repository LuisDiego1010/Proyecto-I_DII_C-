//
// Created by isaac on 9/4/21.
//

#include "Parser.h"
#include "iostream"
#include "MemoryController.h"
#include <nlohmann/json.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/core.hpp>
#include <boost/date_time.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/global_logger_storage.hpp>

using namespace std;

string Parser::logg;
string Parser::out;


Parser *Parser::self;

Parser *Parser::get_Parser() {
    if (self == nullptr) {
        self = new Parser;

    }
    return self;
}

void Parser::Extract_instruction(const string &instruction) {
    cout << instruction << endl;
    std::string jsonstring = instruction;
    nlohmann::json Json = nlohmann::json::parse(jsonstring);
    cout << Json << endl;
    if (Json.contains("type")) {
        if (Json["type"] == "assign") {
            string variable = Json["left"];
            string value = Json["rigth"];
            Assign(variable, value);
        } else if (Json["type"] == "declaration") {
            string type = Json["left"];
            string tag = Json["rigth"];
            Define(tag, type);
        }
    } else {
        Parser::logg +=
                "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Error in the json\n";
    }

}

void Parser::Assign(const string &variable, string value) {
    cout << variable << " =variable" << endl;
    cout << value << " =value" << endl;
    size_t space;
    size_t dot;
    space = variable.find(' ');
    dot = variable.find('.');
    LNode *search;
    string type_string;

    // detect if the code variable is a declaration, structure.propierty or a variable.
    if ((space == std::string::npos || space <= 2) && dot == std::string::npos) {
        search = Controller->search(" "+variable);
        if (search == nullptr) {
            Parser::logg +=
                    "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] \"Error not founded variable\"\n" + variable;
            return;
        }
        type_string = search->getTypeString();
    } else if (space == std::string::npos) {
        //Do structure things
        string structure = variable.substr(0, dot);
        search = Controller->search(structure);
        if (search == nullptr) {
            Parser::logg +=
                    "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] \"Error not founded variable\"\n" + variable;
            return;
        }
        string propierti = variable.substr(dot, string::npos);
        auto *ptr = static_cast<Scope *>(search->getValue());
        ptr->Search(propierti);
        string type = ptr->getType();
        if (type == "int") {
            search = ptr->getInts()->getNode(propierti);
        } else if (type == "char") {
            search = ptr->getChars()->getNode(propierti);
        } else if (type == "float") {
            search = ptr->getFloats()->getNode(propierti);
        } else if (type == "struct") {
            search = ptr->getStructs()->getNode(propierti);
        } else if (type == "reference") {
            search = ptr->getReferences()->getNode(propierti);
        } else if (type == "long") {
            search = ptr->getLongs()->getNode(propierti);
        } else if (type == "double") {
            search = ptr->getDoubles()->getNode(propierti);
        }
        if (search == nullptr) {
            Parser::logg +=
                    "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] The definition of the assign can not be processed \n" + structure + propierti;
            return;
        }
        type_string = search->getTypeString();
    } else {
        string type = variable.substr(0, space);
        string tag = variable.substr(space, string::npos);
        search = Define(tag, type);
        if (search == nullptr) {
            Parser::logg +=
                    "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] The definition of the assign can not be processed \n" + type + tag;
            return;
        }
        type_string = search->getTypeString();
    }

    auto operation_value = Instruction_Aux(value);
    if (operation_value == "False") {
        Parser::logg +=
                "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Error operation calculation failed \n";
        return;
    }

    if (type_string == "int") {
        *(int *) search->getValue() = static_cast<int>(std::stof(operation_value));
    } else if (type_string == "char") {
        *(char *) search->getValue() = *value.data();
    } else if (type_string == "float") {
        *(float *) search->getValue() = (std::stof(operation_value));
    } else if (type_string == "long") {
        *(long *) search->getValue() = static_cast<long>(std::stof(operation_value));
    } else if (type_string == "double") {
        *(double *) search->getValue() = static_cast<double>(std::stof(operation_value));
    }
}

LNode *Parser::Define(const string &tag, const string &type) {
    cout << type << " =type" << endl;
    cout << tag << " =tag" << endl;
    LNode *returner = nullptr;
    if (type == "int") {
        returner = Controller->define_ints(tag);
    } else if (type == "char") {
        returner = Controller->define_chars(tag);
    } else if (type == "float") {
        returner = Controller->define_floats(tag);
    } else if (type == "struct") {
        returner = Controller->define_structs(tag);
    } else if (type == "reference") {
        returner = Controller->define_references(tag);
    } else if (type == "long") {
        returner = Controller->define_longs(tag);
    } else if (type == "double") {
        returner = Controller->define_doubles(tag);
    } else if (type == "scope") {
        Controller->new_scope();
    } else if (type == "unscope") {
        Controller->Unscope();
    }
    if (returner == nullptr) {
        Parser::logg +=
                "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Error in definiton of variable, overloading tag? \n" + tag;
    }
    return returner;
}

Parser::Parser() {
    if (Controller != nullptr) {
        return;
    }
    Controller = new MemoryController;

    if (self == nullptr) {
        self = this;

    }
}

LNode *Parser::Aux_Assign(const string &variable) {
    size_t space;
    size_t dot;
    dot = variable.find('.');
    LNode *search = nullptr;
    string type_string;

    // detect if the code variable is a structure.propierty or a variable.
    if (dot == std::string::npos) {
        search = Controller->search(variable);
        if (search == nullptr) {
            Parser::logg +=
                    "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Not founded variable\n" + variable;
            return search;
        }
    } else {
        //Do structure things
        string structure = variable.substr(0, dot);
        search = Controller->search(structure);
        if (search == nullptr) { return nullptr; }
        string propierti = variable.substr(dot, string::npos);
        auto *ptr = static_cast<Scope *>(search->getValue());
        ptr->Search(propierti);
        string type = ptr->getType();
        if (type == "int") {
            search = ptr->getInts()->getNode(propierti);
        } else if (type == "char") {
            search = ptr->getChars()->getNode(propierti);
        } else if (type == "float") {
            search = ptr->getFloats()->getNode(propierti);
        } else if (type == "struct") {
            search = ptr->getStructs()->getNode(propierti);
        } else if (type == "reference") {
            search = ptr->getReferences()->getNode(propierti);
        } else if (type == "long") {
            search = ptr->getLongs()->getNode(propierti);
        } else if (type == "double") {
            search = ptr->getDoubles()->getNode(propierti);
        }
    }
    return search;
}

string Parser::Instruction_Aux(string instruction) {
    string result;
    size_t rest;
    size_t sum;
    size_t divide;
    size_t multy;
    sum = instruction.find('+');
    rest = instruction.find('-');
    divide = instruction.find('/');
    multy = instruction.find('*');

    try {
        if (sum != string::npos) {
            LNode *first = Aux_Assign(instruction.substr(0, sum));
            LNode *second = Aux_Assign(instruction.substr(sum, string::npos));
            if (first == nullptr & second == nullptr) {
                try {
                    float value = stof(instruction.substr(0, sum)) + stof(instruction.substr(sum, string::npos));
                }
                catch (exception &e) {
                    cout << "exception while calculating " << instruction.substr(0, sum) << "+"
                         << instruction.substr(sum, string::npos) << endl;
                    cout << "exception:" << e.what() << endl;
                    Parser::logg +=
                            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Catch exception\n" + e.what();
                }
            }
            if (second == nullptr) {
                double left_side;
                const string &type = first->getTypeString();
                if (type == "int") {
                    left_side = *(int *) first->getValue();

                } else if (type == "float") {
                    left_side = *(float *) first->getValue();

                } else if (type == "long") {
                    left_side = *(long *) first->getValue();

                } else if (type == "double") {
                    left_side = *(double *) first->getValue();
                }
                float value = left_side + stof(instruction.substr(sum, string::npos));
                return std::to_string(value);
            }
            if (second != nullptr & first != nullptr) {
                string type = first->getTypeString();
                double left_side;
                if (type == "int") {
                    left_side = *(int *) first->getValue();

                } else if (type == "float") {
                    left_side = *(float *) first->getValue();

                } else if (type == "long") {
                    left_side = *(long *) first->getValue();

                } else if (type == "double") {
                    left_side = *(double *) first->getValue();

                }
                double rigth;
                type = second->getTypeString();
                if (type == "int") {
                    rigth = *(int *) second->getValue();

                } else if (type == "float") {
                    rigth = *(float *) second->getValue();

                } else if (type == "long") {
                    rigth = *(long *) second->getValue();

                } else if (type == "double") {
                    rigth = *(double *) second->getValue();
                }
                float value = left_side + rigth;
                return std::to_string(value);
            }
            return "False";
        }
    }
    catch (exception &e) {
        cout << "exception while calculating " << instruction.substr(0, rest) << "+"
             << instruction.substr(rest, string::npos) << endl;
        cout << "exception:" << e.what() << endl;
        Parser::logg +=
                "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Catch exception\n" + e.what();
    }

    try {
        if (rest != string::npos) {
            LNode *first = Aux_Assign(instruction.substr(0, rest));
            LNode *second = Aux_Assign(instruction.substr(rest, string::npos));
            if (first == nullptr & second == nullptr) {
                try {
                    float value = stof(instruction.substr(0, rest)) - stof(instruction.substr(rest, string::npos));
                }
                catch (exception &e) {
                    cout << "exception while calculating " << instruction.substr(0, rest) << "+"
                         << instruction.substr(rest, string::npos) << endl;
                    cout << "exception:" << e.what() << endl;
                    Parser::logg +=
                            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Catch exception\n" + e.what();
                }
            }
            if (second == nullptr) {
                double left_side;
                const string &type = first->getTypeString();
                if (type == "int") {
                    left_side = *(int *) first->getValue();

                } else if (type == "float") {
                    left_side = *(float *) first->getValue();

                } else if (type == "long") {
                    left_side = *(long *) first->getValue();

                } else if (type == "double") {
                    left_side = *(double *) first->getValue();
                }
                float value = left_side - stof(instruction.substr(rest, string::npos));
                return std::to_string(value);
            }
            if (second != nullptr & first != nullptr) {
                string type = first->getTypeString();
                double left_side;
                if (type == "int") {
                    left_side = *(int *) first->getValue();

                } else if (type == "float") {
                    left_side = *(float *) first->getValue();

                } else if (type == "long") {
                    left_side = *(long *) first->getValue();

                } else if (type == "double") {
                    left_side = *(double *) first->getValue();

                }
                double rigth;
                type = second->getTypeString();
                if (type == "int") {
                    rigth = *(int *) second->getValue();

                } else if (type == "float") {
                    rigth = *(float *) second->getValue();

                } else if (type == "long") {
                    rigth = *(long *) second->getValue();

                } else if (type == "double") {
                    rigth = *(double *) second->getValue();
                }
                float value = left_side - rigth;
                return std::to_string(value);
            }
            return "False";
        }
    }
    catch (exception &e) {
        cout << "exception while calculating " << instruction.substr(0, rest) << "-"
             << instruction.substr(rest, string::npos) << endl;
        cout << "exception:" << e.what() << endl;
        Parser::logg +=
                "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Catch exception\n" + e.what();
    }

    try {
        if (divide != string::npos) {
            LNode *first = Aux_Assign(instruction.substr(0, divide));
            LNode *second = Aux_Assign(instruction.substr(divide, string::npos));
            if (first == nullptr & second == nullptr) {
                try {
                    float value = stof(instruction.substr(0, divide)) + stof(instruction.substr(divide, string::npos));
                }
                catch (exception &e) {
                    cout << "exception while calculating " << instruction.substr(0, divide) << "+"
                         << instruction.substr(divide, string::npos) << endl;
                    cout << "exception:" << e.what() << endl;
                    Parser::logg +=
                            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Catch exception\n" + e.what();
                }
            }
            if (second == nullptr) {
                double left_side;
                const string &type = first->getTypeString();
                if (type == "int") {
                    left_side = *(int *) first->getValue();

                } else if (type == "float") {
                    left_side = *(float *) first->getValue();

                } else if (type == "long") {
                    left_side = *(long *) first->getValue();

                } else if (type == "double") {
                    left_side = *(double *) first->getValue();
                }
                try {
                    float value = left_side / stof(instruction.substr(sum, string::npos));
                    return std::to_string(value);
                } catch (exception &e) {
                    cout << "exception while calculating " << instruction.substr(0, divide) << "/"
                         << instruction.substr(divide, string::npos) << endl;
                    cout << "exception:" << e.what() << endl;
                    Parser::logg +=
                            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Catch exception\n" + e.what();
                }
                return "False";
            }
            if (second != nullptr & first != nullptr) {
                string type = first->getTypeString();
                double left_side;
                if (type == "int") {
                    left_side = *(int *) first->getValue();

                } else if (type == "float") {
                    left_side = *(float *) first->getValue();

                } else if (type == "long") {
                    left_side = *(long *) first->getValue();

                } else if (type == "double") {
                    left_side = *(double *) first->getValue();

                }
                double rigth;
                type = second->getTypeString();
                if (type == "int") {
                    rigth = *(int *) second->getValue();

                } else if (type == "float") {
                    rigth = *(float *) second->getValue();

                } else if (type == "long") {
                    rigth = *(long *) second->getValue();

                } else if (type == "double") {
                    rigth = *(double *) second->getValue();
                }
                try {
                    float value = left_side / rigth;
                    return std::to_string(value);
                } catch (exception &e) {
                    cout << "exception while calculating " << instruction.substr(0, divide) << "/"
                         << instruction.substr(divide, string::npos) << endl;
                    cout << "exception:" << e.what() << endl;
                    Parser::logg +=
                            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Catch exception\n" + e.what();
                }
                return "False";
            }
            return "False";
        }
    }
    catch (exception &e) {
        cout << "exception while calculating " << instruction.substr(0, rest) << "/"
             << instruction.substr(rest, string::npos) << endl;
        cout << "exception:" << e.what() << endl;
        Parser::logg +=
                "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Catch exception\n" + e.what();
    }

    try {
        if (multy != string::npos) {
            LNode *first = Aux_Assign(instruction.substr(0, multy));
            LNode *second = Aux_Assign(instruction.substr(multy, string::npos));
            if (first == nullptr & second == nullptr) {
                try {
                    float value = stof(instruction.substr(0, multy)) * stof(instruction.substr(multy, string::npos));
                }
                catch (exception &e) {
                    cout << "exception while calculating " << instruction.substr(0, multy) << "*"
                         << instruction.substr(multy, string::npos) << endl;
                    cout << "exception:" << e.what() << endl;
                    Parser::logg +=
                            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Catch exception\n" + e.what();
                }
            }
            if (second == nullptr) {
                double left_side;
                const string &type = first->getTypeString();
                if (type == "int") {
                    left_side = *(int *) first->getValue();

                } else if (type == "float") {
                    left_side = *(float *) first->getValue();

                } else if (type == "long") {
                    left_side = *(long *) first->getValue();

                } else if (type == "double") {
                    left_side = *(double *) first->getValue();
                }
                float value = left_side * stof(instruction.substr(multy, string::npos));
                return std::to_string(value);
            }
            if (second != nullptr & first != nullptr) {
                string type = first->getTypeString();
                double left_side;
                if (type == "int") {
                    left_side = *(int *) first->getValue();

                } else if (type == "float") {
                    left_side = *(float *) first->getValue();

                } else if (type == "long") {
                    left_side = *(long *) first->getValue();

                } else if (type == "double") {
                    left_side = *(double *) first->getValue();

                }
                double rigth;
                type = second->getTypeString();
                if (type == "int") {
                    rigth = *(int *) second->getValue();

                } else if (type == "float") {
                    rigth = *(float *) second->getValue();

                } else if (type == "long") {
                    rigth = *(long *) second->getValue();

                } else if (type == "double") {
                    rigth = *(double *) second->getValue();
                }
                float value = left_side * rigth;
                return std::to_string(value);
            }
            return "False";
        }
    }
    catch (exception &e) {
        cout << "exception while calculating " << instruction.substr(0, rest) << "*"
             << instruction.substr(rest, string::npos) << endl;
        cout << "exception:" << e.what() << endl;
        Parser::logg +=
                "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Catch exception\n" + e.what();
    }


    return instruction;

}

string Parser::Generate_Json() {
    string JS;
    nlohmann::json Json;
    JS = Controller->getMainScope()->GetJson();
    Json["Memory"] = JS;
    Json["out"] = "";
    Json["logger"] = logg;
    return to_string(Json);
}
