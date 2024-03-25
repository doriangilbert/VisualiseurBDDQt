#include "TableViewer.h"
#include "ui_TableViewer.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>

TableViewer::TableViewer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TableViewer)
{
    ui->setupUi(this);
}

void TableViewer::load() {
    // QSqlDatabase bdd = QSqlDatabase::addDatabase("QSQLITE");
    // bdd.setDatabaseName("db_exemple.db");
    // bdd.open();
    // QSqlQueryModel model;
    // model.setQuery("SELECT * FROM Personne");
    // ui->tableView->setModel(model);
    // ui->tableView->show();
}

TableViewer::~TableViewer()
{
    delete ui;
}
