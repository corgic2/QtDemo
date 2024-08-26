#include "widget.h"
#include "ui_widget.h"
#include <QList>
#include <QAbstractItemView>
#include <QAbstractItemModel>
#include <QBrush>
#include <qdebug.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_treeView = ui->treeView;
    m_treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    m_treeView->setEditTriggers(QTreeView::NoEditTriggers);
//    m_treeView->setTextElideMode(Qt::ElideRight);
//    m_treeView->setToolTip();
    m_brush = QBrush(Qt::red);

    m_model = new QStandardItemModel;
    m_model->setHorizontalHeaderLabels(QStringList() << "文件名" << "文件路径" << "是否更改");

    {
    QStandardItem *rootItem = new QStandardItem("root Item");
    rootItem->setIcon(QIcon(":/images/center3.png"));
    m_model->appendRow(rootItem);
    QStandardItem* child1 = new QStandardItem("Child 1");
    QStandardItem* child2 = new QStandardItem("Child 2");
    child1->setIcon(QIcon(":/images/center3.png"));
    child2->setIcon(QIcon(":/images/center3.png"));
    rootItem->appendRow(child1);
    rootItem->appendRow(child2);
    m_font = rootItem->font();
    QList<QStandardItem*> list;
    for(int i = 0;i<3;++i)
    {
        QStandardItem* t = CreateItem(QString::number(i + 1111));
        if(i == 0)
        {
           t->setCheckable(true);
           t->setCheckState(Qt::Unchecked);
        }
        list.append(t);
    }
    child1->appendRow(list);
    child2->appendRow(CreateItem("2-1-123"));
//    child2->appendRow(CreateItem("2-1-12311111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"));
    }
    for(int column = 0;column<m_model->columnCount();++column)
    {
        m_treeView->setColumnWidth(column,400);
    }

    m_treeView->setModel(m_model);
    connect(m_model,&QStandardItemModel::itemChanged,this,&Widget::SlotItemChanged);
}

void Widget::SlotItemChanged(QStandardItem *item){
    QStandardItem* parent = item->parent();
    bool checked = item->checkState() == Qt::Checked;
    QModelIndex index = m_model->indexFromItem(item->parent());
    int columnCount = parent->columnCount();
    for(int column = 0;column<columnCount;++column)
    {
        QStandardItem* t = parent->child(index.row(),column);
        qDebug()<<"the row is"<<index.row()<<"and the column is"<<column<<"and the text is"<<t->text();
        if(checked)
        {
            QFont font = m_font;
            font.setStrikeOut(true);
            QColor color(Qt::black);
            m_model->blockSignals(true);
            t->setFont(font);
            t->setForeground(QBrush(Qt::black));
            m_model->blockSignals(false);
        }
        else
        {
            m_model->blockSignals(true);
            t->setFont(m_font);
            t->setForeground(m_brush);
            m_model->blockSignals(false);
        }
    }
    qDebug()<<checked;
    m_treeView->viewport()->update();
}

QStandardItem* Widget::CreateItem(const QString &text)
{
    QStandardItem * tmp = new QStandardItem(text);
    tmp->setForeground(m_brush);
    return tmp;
}
Widget::~Widget()
{
    delete ui;
}
