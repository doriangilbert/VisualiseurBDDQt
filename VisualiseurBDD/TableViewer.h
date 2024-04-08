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

private slots:
    void on_retourPushButton_clicked();

signals:
    void retourButtonClicked();
};

#endif // TABLEVIEWER_H
