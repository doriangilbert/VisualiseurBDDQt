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
#include <QJsonArray>


class ReadWriteJson
{

public:
    //** Méthodes **//
    bool static readJson();

    bool static writeJson();
};

#endif // READWRITEJSON_H
