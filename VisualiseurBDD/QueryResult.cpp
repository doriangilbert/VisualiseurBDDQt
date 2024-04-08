#include "QueryResult.h"
#include "ui_QueryResult.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "Data.h"

QueryResult::QueryResult(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QueryResult)
{
    ui->setupUi(this);
}

void QueryResult::load() {
    QString chemin = QString::fromStdString(Data::getCurrentBDD().getPath());
    QSqlDatabase bdd = QSqlDatabase::addDatabase("QSQLITE");
    bdd.setDatabaseName(chemin);
    bdd.open();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(QString::fromStdString(Data::getRequete()));
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

QueryResult::~QueryResult()
{
    delete ui;
}

void QueryResult::on_retourPushButton_clicked()
{
    emit retourButtonClicked();
}

