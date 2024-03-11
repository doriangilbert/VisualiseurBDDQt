#include "DatabasesList.h"
#include "ui_DatabasesList.h"
#include "lib/sqlite3.h"

sqlite3* db;
int rc = sqlite3_open("ma_base_de_données.db", &db);
//if (rc != SQLITE_OK)
//{
    // Gestion des erreurs
//}

DatabasesList::DatabasesList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabasesList)
{
    ui->setupUi(this);
}

DatabasesList::~DatabasesList()
{
    delete ui;
}
