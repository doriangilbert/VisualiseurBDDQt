#include "ManageDatabase.h"
#include "ui_ManageDatabase.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>

ManageDatabase::ManageDatabase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ManageDatabase)
{
    ui->setupUi(this);
}

void ManageDatabase::load() {
    QSqlDatabase bdd = QSqlDatabase::addDatabase("QSQLITE");
    bdd.setDatabaseName("Hector.SQLite");
    bdd.open();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT name AS NomTable FROM sqlite_master WHERE type='table'");
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

ManageDatabase::~ManageDatabase()
{
    delete ui;
}
