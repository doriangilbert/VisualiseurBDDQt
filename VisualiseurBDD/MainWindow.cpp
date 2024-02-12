#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Login.h"
#include "CreateUser.h"
#include "ManageUser.h"
#include "SelectProfile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loginWidget = new Login(this);
    loginWidget->show();

    createUserWidget = new CreateUser(this);
    createUserWidget->hide();

    manageUserWidget = new ManageUser(this);
    manageUserWidget->hide();

    selectProfileWidget = new SelectProfile(this);
    selectProfileWidget->hide();

    connect(loginWidget, &Login::loginButtonClicked, this, &MainWindow::goToManageUserFromLogin);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goToManageUserFromLogin() {
    loginWidget->hide();
    manageUserWidget->show();
}

