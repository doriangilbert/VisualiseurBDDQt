#ifndef QUERYMAKER_H
#define QUERYMAKER_H

#include <QWidget>

namespace Ui {
class QueryMaker;
}

class QueryMaker : public QWidget
{
    Q_OBJECT

public:
    explicit QueryMaker(QWidget *parent = nullptr);
    ~QueryMaker();

private:
    Ui::QueryMaker *ui;

private slots:
    void on_executerRequetePushButton_clicked();

    void on_retourPushButton_clicked();

signals:
    void executerRequeteButtonClicked();

    void retourButtonClicked();
};

#endif // QUERYMAKER_H
