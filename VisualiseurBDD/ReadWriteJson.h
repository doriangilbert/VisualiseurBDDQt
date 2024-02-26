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
    //** Attributs **//
    QJsonObject jsonObject;

public:
    //** Méthodes **//
    int static readJson();

    int static writeJson();
};

#endif // READWRITEJSON_H
