#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>

namespace Ui {
class TableView;
}

class TableView : public QWidget
{
    Q_OBJECT

public:
    explicit TableView(QWidget *parent = nullptr);
    ~TableView();

private:
    Ui::TableView *ui;
};

#endif // TABLEVIEW_H
