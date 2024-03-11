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
};

#endif // ADDDATABASE_H
