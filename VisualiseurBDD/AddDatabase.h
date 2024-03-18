#ifndef ADDDATABASE_H
#define ADDDATABASE_H

#include <QWidget>

namespace Ui {
class AddDatabase;
}

class AddDatabase : public QWidget
{
    Q_OBJECT

public:
    explicit AddDatabase(QWidget *parent = nullptr);
    ~AddDatabase();

private:
    Ui::AddDatabase *ui;

private slots:
    void on_retourPushButton_clicked();

signals:
    void retourButtonClicked();
};

#endif // ADDDATABASE_H
