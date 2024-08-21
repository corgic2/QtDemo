#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->horizontalSlider->setStyleSheet("QSlider::groove:horizontal {\
                                        border: 2px solid @color4;\
                                        height: 0px;\
                                        background: #D4D4D4;\
                                        border-radius: 2px;\
                                    }\
                                    QSlider::handle:horizontal {\
                                        background: #249BD9;\
                                        border: 8px solid rgba(0,0,0,0);\
                                        margin: -12px -8px;\
                                        border-radius: 7px;\
                                    }");

}
Widget::~Widget()
{
    delete ui;
}
