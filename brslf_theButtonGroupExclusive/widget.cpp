#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_buttonGroup = new QButtonGroup(this);
    m_buttonGroup->addButton(ui->radioButton);
    m_buttonGroup->addButton(ui->radioButton_2);
    m_buttonGroup->setExclusive(true);
    connect(m_buttonGroup,static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked)
            ,this,static_cast<void (Widget::*)(int)>(&Widget::SlotButtonClicked));
}

Widget::~Widget()
{
    delete m_buttonGroup;
    m_buttonGroup = nullptr;
    delete ui;
}

void Widget::SlotButtonClicked(int cnt)
{
    if(m_buttonGroup->checkedButton() == ui->radioButton)
    {
        LineEditStyleSheet();
    }
    else if(m_buttonGroup->checkedButton() == ui->radioButton_2)
    {
        LineEdit2StyleSheet();
    }
}

void Widget::LineEditStyleSheet()
{
    ui->lineEdit_2->setStyleSheet("");
    ui->lineEdit->setStyleSheet("background-color:#000000;");
}

void Widget::LineEdit2StyleSheet()
{
    ui->lineEdit->setStyleSheet("");
    ui->lineEdit_2->setStyleSheet("background-color:red;");
}

