#ifndef TABLEVIEWER_H
#define TABLEVIEWER_H

#include <QWidget>

namespace Ui {
class TableViewer;
}

class TableViewer : public QWidget
{
    Q_OBJECT

public:
    explicit TableViewer(QWidget *parent = nullptr);
    ~TableViewer();
    void load();

private:
    Ui::TableViewer *ui;
};

#endif // TABLEVIEWER_H
