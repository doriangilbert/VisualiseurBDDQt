#include "ManageUser.h"
#include "ui_ManageUser.h"

ManageUser::ManageUser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ManageUser)
{
    ui->setupUi(this);
}

ManageUser::~ManageUser()
{
    delete ui;
}

void ManageUser::on_selectionProfilPushButton_clicked()
{
    emit selectProfileButtonClicked();
}


void ManageUser::on_seDeconnecterPushButton_clicked()
{
    emit disconnectButtonClicked();
}

