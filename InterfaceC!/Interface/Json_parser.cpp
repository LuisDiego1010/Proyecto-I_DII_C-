//
// Created by isaac on 13/4/21.
//
#include <QTextStream>
#include <cstring>
#include <QJsonObject>
#include <QJsonDocument>
#include "Json_parser.h"

std::string Json_parser::qt_json(QString a) {
    std::string Json_string;
    std::string line = a.toUtf8().constData();
    QJsonObject Json;
    size_t type=line.find('=');
    if (type!=std::string::npos){
        QString left=QString::fromStdString(line.substr(0,type));
        size_t endline=line.find(';');
        QString rigth=QString::fromStdString(line.substr(type+1,endline-1));
        Json["type"]="assign";
        Json["left"]=left;
        Json["rigth"]=rigth;
    }else{
        type=line.find(" ");
        if(type!=std::string::npos){
            QString left=QString::fromStdString(line.substr(0,type));
            QString rigth=QString::fromStdString(line.substr(type,line.length()-type-1));
            Json["type"]="declaration";
            Json["left"]=left;
            Json["rigth"]=rigth;
        }else {
            type=line.find("{");
            if (type<2){
                Json["type"]="scope";
                Json["left"]="{";
                Json["rigth"]="{";
            }else if(type!=std::string::npos){
                QString left=QString::fromStdString(line.substr(0,type-1));
                QString rigth=QString::fromStdString(line.substr(type,line.length()-type-2));
                Json["type"]="struct";
                Json["left"]=left;
                Json["rigth"]=rigth;
            }else{
                type=line.find("}");
                if (type!=std::string::npos){
                    Json["type"]="unscope";
                    Json["left"]="}";
                    Json["rigth"]="}";
                }else{
                    Json["type"]="error";
                    Json["left"]=QString::fromStdString(line);
                }
            }
        }
}
    QJsonDocument doc(Json);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    Json_string= strJson.toUtf8().constData();
    return Json_string;
}
