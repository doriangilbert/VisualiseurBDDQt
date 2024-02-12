#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    class Login *loginWidget;
    class CreateUser *createUserWidget;
    class ManageUser *manageUserWidget;
    class SelectProfile *selectProfileWidget;

public slots:
    void goToManageUserFromLogin();
};

#endif // MAINWINDOW_H
