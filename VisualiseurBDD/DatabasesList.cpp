#include "DatabasesList.h"
#include "ui_DatabasesList.h"

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
