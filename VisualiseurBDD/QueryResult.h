#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <QWidget>

namespace Ui {
class QueryResult;
}

class QueryResult : public QWidget
{
    Q_OBJECT

public:
    explicit QueryResult(QWidget *parent = nullptr);
    ~QueryResult();
    void load();

private:
    Ui::QueryResult *ui;

private slots:
    void on_retourPushButton_clicked();

signals:
    void retourButtonClicked();
};

#endif // QUERYRESULT_H
