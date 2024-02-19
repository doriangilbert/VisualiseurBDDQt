#include "Login.h"
#include "ui_Login.h"
#include <string>
#include <iostream>
using namespace std;

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_seConnecterPushButton_clicked()
{
    string identifiant = ui->identifiantLineEdit->text().toStdString();
    string motDePasse = ui->motDePasseLineEdit->text().toStdString();
    cout << identifiant << " | " << motDePasse << endl;
    ui->identifiantLineEdit->setText(0);
    ui->motDePasseLineEdit->setText(0);
    emit loginButtonClicked();
}

