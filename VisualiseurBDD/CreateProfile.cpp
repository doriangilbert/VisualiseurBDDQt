#include "CreateProfile.h"
#include "ui_CreateProfile.h"
#include "Profile.h"
#include "Data.h"
#include "ReadWriteJson.h"

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
    Profile newProfile = Profile(nomProfil);

    User currentUser = Data::getCurrentUser();
    currentUser.AddProfile(newProfile);
    Data::setCurrentUser(currentUser);
    Data::deleteUser(Data::getCurrentUser().getIdentifier());
    Data::addUser(currentUser);
    Data::getCurrentUser().AddProfile(newProfile);
    ReadWriteJson qjson;
    qjson.writeJson();
    ui->nomProfilLineEdit->setText(0);
    emit validateButtonClicked();
}

