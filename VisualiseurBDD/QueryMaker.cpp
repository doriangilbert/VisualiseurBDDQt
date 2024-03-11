#include "QueryMaker.h"
#include "ui_QueryMaker.h"

QueryMaker::QueryMaker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QueryMaker)
{
    ui->setupUi(this);
}

QueryMaker::~QueryMaker()
{
    delete ui;
}
