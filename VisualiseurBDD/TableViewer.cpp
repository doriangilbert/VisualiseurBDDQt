#include "TableViewer.h"
#include "ui_TableViewer.h"
#include "Data.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QFileInfo>

TableViewer::TableViewer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TableViewer)
{
    ui->setupUi(this);
}

void TableViewer::load() {

    QString chemin = QString::fromStdString(Data::getCurrentBDD().getPath());
    QSqlDatabase bdd = QSqlDatabase::addDatabase("QSQLITE");
    bdd.setDatabaseName(chemin);
    bdd.open();
    QSqlQueryModel *model = new QSqlQueryModel();
    QString requete = "SELECT * FROM " + QString::fromStdString(Data::getTable());
    model->setQuery(requete);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

TableViewer::~TableViewer()
{
    delete ui;
}

void TableViewer::on_retourPushButton_clicked()
{
    emit retourButtonClicked();
}

