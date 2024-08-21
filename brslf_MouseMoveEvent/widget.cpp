#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(dragging)
    {
        QPoint delta = event->pos() - myPoint;
        move(pos() + delta);
        myPoint = event->pos();
    }
    return QWidget::mouseMoveEvent(event);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragging = true;
        myPoint = event->pos();
    }
    return QWidget::mousePressEvent(event);
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragging = false;
    }
    return QWidget::mouseReleaseEvent(event);
}
