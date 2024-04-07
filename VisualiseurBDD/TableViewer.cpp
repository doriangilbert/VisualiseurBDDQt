#include "TableViewer.h"
#include "ui_TableViewer.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>

TableViewer::TableViewer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TableViewer)
{
    ui->setupUi(this);
}

void TableViewer::load() {
    QSqlDatabase bdd = QSqlDatabase::addDatabase("QSQLITE");
    bdd.setDatabaseName("Hector.SQLite");
    bdd.open();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Articles");
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

TableViewer::~TableViewer()
{
    delete ui;
}
