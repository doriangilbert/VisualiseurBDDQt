#ifndef CREATEUSER_H
#define CREATEUSER_H

#include <QWidget>

namespace Ui {
class CreateUser;
}

class CreateUser : public QWidget
{
    Q_OBJECT

public:
    explicit CreateUser(QWidget *parent = nullptr);
    ~CreateUser();

private:
    Ui::CreateUser *ui;

private slots:
    void on_validerPushButton_clicked();

signals:
    void validateButtonClicked();
};

#endif // CREATEUSER_H
