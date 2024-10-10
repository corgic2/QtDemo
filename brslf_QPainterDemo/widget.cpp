#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPoint>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}
void Widget::paintEvent(QPaintEvent *event)
{
    int x = 100,y = 100;
    int width = 100,height = 100;
    QPainter painter(this);
    {
        //设置画笔 QPen(Qbrush , width)
        painter.setPen(QPen(Qt::red,2));
        painter.setBrush(QBrush(Qt::blue));
    }
    {
        //设置抗锯齿
        painter.setRenderHint(QPainter::Antialiasing);
        /*
         * QPainter::Antialiasing 抗锯齿
         * QPainter::TextAntialiasing 抗锯齿
         * QPainter::SmoothPixmapTransform 平滑像素图
        */
    }
    {
        //矩形 QRect(x,y,width,height) QRect(QPoint topleft,QPoint bottomright)
        //painter.drawRect(QRect(x,y,width,height));
        //圆角矩形 xRadius yRadius
        //painter.drawRoundedRect(QRect(x,y,width,height - 50),5,5);
    }
    {
        //倒三角形
        //painter.drawLine(QPoint(x,y),QPoint(x + 100,y));
        //painter.drawLine(QPoint(x + 100,y),QPoint(x + 50,y + 50));
        //painter.drawLine(QPoint(x + 50,y + 50),QPoint(x,y));
    }
    {
        //圆  圆心 + rx + ry
        //painter.drawEllipse(QPoint(100,100),40,40);
        //扇形 注意扇形中一个圆为5760°，即16 * 360 参数表示 startAngle,endAngle
        //painter.drawPie(QRect(x,y,width,height),0,2880);
        //圆弧 同扇形， 只不过没有边只有弧
        //painter.drawArc(x,y,width,height,0,2880);
    }

}
Widget::~Widget()
{
    delete ui;
}
