#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,stop: 0 #14F4FF, stop: 1 #1499FF);font:16pt;");
}

Widget::~Widget()
{
    delete ui;
}
