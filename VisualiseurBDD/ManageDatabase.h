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

private:
    Ui::ManageDatabase *ui;
};

#endif // MANAGEDATABASE_H
