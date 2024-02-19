#ifndef MANAGEUSER_H
#define MANAGEUSER_H

#include <QWidget>

namespace Ui {
class ManageUser;
}

class ManageUser : public QWidget
{
    Q_OBJECT

public:
    explicit ManageUser(QWidget *parent = nullptr);
    ~ManageUser();

private:
    Ui::ManageUser *ui;

private slots:
    void on_selectionProfilPushButton_clicked();
    void on_seDeconnecterPushButton_clicked();

signals:
    void selectProfileButtonClicked();
    void disconnectButtonClicked();
};

#endif // MANAGEUSER_H
