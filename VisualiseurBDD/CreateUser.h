#ifndef CREATEUSER_H
#define CREATEUSER_H

#include <QMainWindow>

namespace Ui {
class CreateUser;
}

class CreateUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateUser(QWidget *parent = nullptr);
    ~CreateUser();

private:
    Ui::CreateUser *ui;
};

#endif // CREATEUSER_H
