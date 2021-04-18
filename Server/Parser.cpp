//
// Created by isaac on 9/4/21.
//

#include "Parser.h"
#include "iostream"
#include <nlohmann/json.hpp>

using namespace std;

Parser *Parser ::self;

Parser *Parser::get_Parser() {
    if (self== nullptr){
        self =new Parser;
    }
    return self;
}

void Parser::Extract_instruction(const string& instruction) {
    cout<<instruction<<endl;
    std::string jsonstring= instruction;
    nlohmann::json Json = nlohmann::json::parse(jsonstring);
    cout<<Json<<endl;
    if (Json.contains("type")){
        if(Json["type"]=="assign"){
        string variable=Json["left"];
        string value=Json["rigth"];
        cout<<variable<<" =variable"<<endl;
        cout<<value<<" =value"<<endl;
        }else
            if (Json["type"]=="declaration"){
                string type=Json["left"];
                string tag=Json["rigth"];
                cout<<left<<" =type"<<endl;
                cout<<right<<" =tag"<<endl;
                if(type=="int"){
                    Controller->define_ints(tag);
                }else if(type=="char"){
                    Controller->define_chars(tag);
                }else if(type=="float"){
                    Controller->define_floats(tag);
                }else if(type=="struct"){
                    Controller->define_structs(tag);
                }else if(type=="reference"){
                    Controller->define_references(tag);
                }else if(type=="long"){
                    Controller->define_longs(tag);
                }else if(type=="double"){
                    Controller->define_doubles(tag);
                }else{
                    Controller->new_scope();
                }

            }
    }else {
        cout<<right<<" Error in the json"<<endl;
    }
}

void Parser::Instruction_Aux(string instruction) {

}

void Parser::Define_assign(string id, string type, string value) {

}

void Parser::Assign(string id, string value) {

}

void Parser::Define(string id, string type) {

}
