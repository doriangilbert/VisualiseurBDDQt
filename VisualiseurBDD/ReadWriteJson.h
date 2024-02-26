#ifndef READWRITEJSON_H
#define READWRITEJSON_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonArray>
#include <QCoreApplication>
#include <QFile>
#include <QDebug>

class ReadWriteJson
{
private:
    //** Attributes **//
    QJsonObject jsonObject;

public:
    QJsonObject getJsonObject();

    void setJsonObject(QJsonObject jsonObject);

    int readJson();

    int static writeJson();
};

#endif // READWRITEJSON_H
