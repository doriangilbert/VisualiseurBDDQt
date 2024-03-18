#include "QueryResult.h"
#include "ui_QueryResult.h"

QueryResult::QueryResult(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QueryResult)
{
    ui->setupUi(this);
}

QueryResult::~QueryResult()
{
    delete ui;
}
