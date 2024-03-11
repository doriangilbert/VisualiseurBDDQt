#include "ManageDatabase.h"
#include "ui_ManageDatabase.h"

ManageDatabase::ManageDatabase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ManageDatabase)
{
    ui->setupUi(this);
}

ManageDatabase::~ManageDatabase()
{
    delete ui;
}
