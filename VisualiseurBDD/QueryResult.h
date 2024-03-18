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

private:
    Ui::QueryResult *ui;
};

#endif // QUERYRESULT_H
