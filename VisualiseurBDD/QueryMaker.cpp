#include "QueryMaker.h"
#include "ui_QueryMaker.h"
#include "Data.h"

QueryMaker::QueryMaker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QueryMaker)
{
    ui->setupUi(this);
}

QueryMaker::~QueryMaker()
{
    delete ui;
}

void QueryMaker::on_executerRequetePushButton_clicked()
{
    std::string requete = ui->requetePlainTextEdit->toPlainText().toStdString();

    if (!requete.empty()) {
        Data::setRequete(requete);
        ui->requetePlainTextEdit->setPlainText(0);
    }

    emit executerRequeteButtonClicked();
}


void QueryMaker::on_retourPushButton_clicked()
{
    emit retourButtonClicked();
}

