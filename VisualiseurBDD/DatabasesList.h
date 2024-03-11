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

private:
    Ui::DatabasesList *ui;
};

#endif // DATABASESLIST_H
