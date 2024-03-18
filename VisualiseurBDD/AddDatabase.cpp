#include "AddDatabase.h"
#include "ui_AddDatabase.h"

AddDatabase::AddDatabase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddDatabase)
{
    ui->setupUi(this);
}

AddDatabase::~AddDatabase()
{
    delete ui;
}

void AddDatabase::on_retourPushButton_clicked()
{
    emit retourButtonClicked();
}

