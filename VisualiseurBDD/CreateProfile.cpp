#include "CreateProfile.h"
#include "ui_CreateProfile.h"

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
