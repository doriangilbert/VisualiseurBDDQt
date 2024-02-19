#include "CreateUser.h"
#include "ui_CreateUser.h"
#include <string>
#include <iostream>
using namespace std;

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

void CreateUser::on_validerPushButton_clicked()
{
    string nom = ui->nomLineEdit->text().toStdString();
    string prenom = ui->prenomLineEdit->text().toStdString();
    string identifiant = ui->identifiantLineEdit->text().toStdString();
    string motDePasse = ui->motDePasseLineEdit->text().toStdString();
    string confirmationMotDePasse = ui->confirmationMotDePasseLineEdit->text().toStdString();
    bool isAdmin = ui->adminCheckBox->isChecked();
    cout << nom << " | " << prenom << " | " << identifiant << " | " << motDePasse << " | " << confirmationMotDePasse << " | " << isAdmin << endl;
    ui->nomLineEdit->setText(0);
    ui->prenomLineEdit->setText(0);
    ui->identifiantLineEdit->setText(0);
    ui->motDePasseLineEdit->setText(0);
    ui->confirmationMotDePasseLineEdit->setText(0);
    ui->adminCheckBox->setChecked(0);
    emit validateButtonClicked();
}

