#include "TableView.h"
#include "ui_TableView.h"

TableView::TableView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TableView)
{
    ui->setupUi(this);
}

TableView::~TableView()
{
    delete ui;
}
