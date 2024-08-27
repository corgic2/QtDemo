#include "widget.h"
#include "ui_widget.h"
#include <QBrush>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_itemModel = new QStandardItemModel;
    m_listView = ui->listView;
    m_listView->setModel(m_itemModel);

    m_itemModel->setColumnCount(4);
    m_itemModel->setHeaderData(0,Qt::Horizontal,tr("文件名"));
    m_itemModel->setHeaderData(1,Qt::Horizontal,tr("文件路径"));
    m_itemModel->setHeaderData(2,Qt::Horizontal,tr("行数"));
    m_itemModel->setHeaderData(3,Qt::Horizontal,tr("内容"));
    connect(m_itemModel,&QStandardItemModel::itemChanged,this,&Widget::SlotItemChanged);

}
void Widget::CreateItem(const QString &text)
{
    auto *item = new QStandardItem(QString("Item %1").arg(i));
    m_itemModel->appendRow(item);
    item->setForeground(QBrush(Qt::red));
    item->setCheckable(true);
    item->setCheckState(Qt::Unchecked);
}
void Widget::ChangeItemStyle(QStandardItem *item, bool checked)
{
    if(item && checked)
    {
        QFont font = m_font;
        font.setStrikeOut(true);
        m_itemModel->blockSignals(true);
        item->setFont(font);
        item->setForeground(QBrush(Qt::black));
        m_itemModel->blockSignals(false);
    }
    else
    {
        m_itemModel->blockSignals(true);
        item->setFont(m_font);
        item->setForeground(QBrush(Qt::red));
        m_itemModel->blockSignals(false);
    }
}

void Widget::SlotItemChanged(QStandardItem *item){
    bool checked = item->checkState() == Qt::Checked;
    ChangeItemStyle(item,checked);
    m_listView->viewport()->update();
}

Widget::~Widget()
{
    delete ui;
}
