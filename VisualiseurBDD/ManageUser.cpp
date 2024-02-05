#include "ManageUser.h"
#include "ui_ManageUser.h"

ManageUser::ManageUser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ManageUser)
{
    ui->setupUi(this);
}

ManageUser::~ManageUser()
{
    delete ui;
}
