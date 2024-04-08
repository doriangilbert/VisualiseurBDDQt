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

    string chemin = Data::getCurrentBDD().getPath();
    QFileInfo fileInfoBdd(QString::fromStdString(chemin));
    QString fileNameBdd = fileInfoBdd.fileName();

    QSqlDatabase bdd = QSqlDatabase::addDatabase(QString::fromStdString(chemin));
    bdd.setDatabaseName(fileNameBdd);
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
