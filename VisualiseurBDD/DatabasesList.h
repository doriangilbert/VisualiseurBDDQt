#ifndef DATABASESLIST_H
#define DATABASESLIST_H

#include <QWidget>

namespace Ui {
class DatabasesList;
}

class DatabasesList : public QWidget
{
    Q_OBJECT

public:
    explicit DatabasesList(QWidget *parent = nullptr);
    ~DatabasesList();
    void load();

private:
    Ui::DatabasesList *ui;

private slots:
    void on_retourPushButton_clicked();

    void on_ajouterBasePushButton_clicked();

    void on_supprimerPushButton_clicked();

signals:
    void retourButtonClicked();

    void tableViewClicked();
};

#endif // DATABASESLIST_H
