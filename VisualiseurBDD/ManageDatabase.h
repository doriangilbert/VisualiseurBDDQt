#ifndef MANAGEDATABASE_H
#define MANAGEDATABASE_H

#include <QWidget>

namespace Ui {
class ManageDatabase;
}

class ManageDatabase : public QWidget
{
    Q_OBJECT

public:
    explicit ManageDatabase(QWidget *parent = nullptr);
    ~ManageDatabase();
    void load();

private:
    Ui::ManageDatabase *ui;

private slots:
    void on_effectuerRequetePushButton_clicked();

    void on_retourPushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

signals:
    void effectuerRequeteButtonClicked();

    void retourButtonClicked();

    void tableViewClicked();
};

#endif // MANAGEDATABASE_H
