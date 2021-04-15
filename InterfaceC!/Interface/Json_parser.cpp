//
// Created by isaac on 13/4/21.
//
#include <QTextStream>
#include <cstring>
#include <QJsonObject>
#include <QJsonDocument>
#include "Json_parser.h"
#include "json.hpp"

std::string Json_parser::qt_json(QString a) {
    std::string Json_string;
    std::string line = a.toUtf8().constData();
    QJsonObject Json;
    size_t type=line.find('=');
    if (type!=std::string::npos){
        QString left=QString::fromStdString(line.substr(0,type));
        QString rigth=QString::fromStdString(line.substr(type,line.length()-type));
        Json["type"]="assign";
        Json["left"]=left;
        Json["rigth"]=rigth;
    }else{
        type=line.find(" ");
        if(type!=std::string::npos){
            QString left=QString::fromStdString(line.substr(0,type));
            QString rigth=QString::fromStdString(line.substr(type,line.length()-type));
            Json["type"]="Declaration";
            Json["left"]=left;
            Json["rigth"]=rigth;
        }
}
    QJsonDocument doc(Json);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    Json_string= strJson.toUtf8().constData();
    return Json_string;
}
