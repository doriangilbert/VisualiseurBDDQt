#include "CreateProfile.h"
#include "ui_CreateProfile.h"
#include "Profile.h"
#include <iostream>
#include "Data.h"

CreateProfile::CreateProfile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateProfile)
{
    ui->setupUi(this);
}

CreateProfile::~CreateProfile()
{
    delete ui;
}

void CreateProfile::on_validerPushButton_clicked()
{
    string nomProfil = ui->nomProfilLineEdit->text().toStdString();
    cout << nomProfil << endl;
    Profile newProfile = Profile(nomProfil);
    Data::getCurrentUser().AddProfile(newProfile);
    ui->nomProfilLineEdit->setText(0);
    emit validateButtonClicked();
}

