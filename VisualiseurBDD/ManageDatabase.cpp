#include "ManageDatabase.h"
#include "ui_ManageDatabase.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "Data.h"

ManageDatabase::ManageDatabase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ManageDatabase)
{
    ui->setupUi(this);
}

void ManageDatabase::load() {
    QString chemin = QString::fromStdString(Data::getCurrentBDD().getPath());
    QSqlDatabase bdd = QSqlDatabase::addDatabase("QSQLITE");
    bdd.setDatabaseName(chemin);
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

void ManageDatabase::on_effectuerRequetePushButton_clicked()
{
    emit effectuerRequeteButtonClicked();
}


void ManageDatabase::on_supprimerBasePushButton_clicked()
{

}


void ManageDatabase::on_retourPushButton_clicked()
{
    emit retourButtonClicked();
}


void ManageDatabase::on_tableView_clicked(const QModelIndex &index)
{
    if(index.isValid()) {
        QVariant valeurCellule = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0));
        Data::setTable(valeurCellule.toString().toStdString());
        emit tableViewClicked();
    }
}

