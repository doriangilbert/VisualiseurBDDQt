#include "SelectProfile.h"
#include "ui_SelectProfile.h"

SelectProfile::SelectProfile(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SelectProfile)
{
    ui->setupUi(this);
}

SelectProfile::~SelectProfile()
{
    delete ui;
}
