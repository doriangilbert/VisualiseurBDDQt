#include "CreateUser.h"
#include "ui_CreateUser.h"

CreateUser::CreateUser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateUser)
{
    ui->setupUi(this);
}

CreateUser::~CreateUser()
{
    delete ui;
}
