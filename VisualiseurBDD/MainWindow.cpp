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
    loginWidget->hide();

    createUserWidget = new CreateUser(this);
    createUserWidget->show();

    manageUserWidget = new ManageUser(this);
    manageUserWidget->hide();

    selectProfileWidget = new SelectProfile(this);
    selectProfileWidget->hide();

    connect(loginWidget, &Login::loginButtonClicked, this, &MainWindow::goToManageUserFromLogin);
    connect(manageUserWidget, &ManageUser::selectProfileButtonClicked, this, &MainWindow::goToSelectProfileFromManageUser);
    connect(manageUserWidget, &ManageUser::disconnectButtonClicked, this, &MainWindow::goToLoginFromManageUser);
    connect(selectProfileWidget, &SelectProfile::validateButtonClicked, this, &MainWindow::goToManageUserFromSelectProfile);
    connect(createUserWidget, &CreateUser::validateButtonClicked, this, &MainWindow::goToLoginFromCreateUser);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goToManageUserFromLogin() {
    loginWidget->hide();
    manageUserWidget->show();
}

void MainWindow::goToSelectProfileFromManageUser() {
    manageUserWidget->hide();
    selectProfileWidget->show();
}

void MainWindow::goToLoginFromManageUser() {
    manageUserWidget->hide();
    loginWidget->show();
}

void MainWindow::goToManageUserFromSelectProfile() {
    selectProfileWidget->hide();
    manageUserWidget->show();
}

void MainWindow::goToLoginFromCreateUser() {
    createUserWidget->hide();
    loginWidget->show();
}
