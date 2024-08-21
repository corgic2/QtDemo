#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QFont>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QStandardItem* CreateItem(const QString& text);
    void SlotItemChanged(QStandardItem * item);
private:
    Ui::Widget *ui;
    QTreeView * m_treeView = nullptr;
    QStandardItemModel* m_model = nullptr;
    QFont m_font;
    QBrush m_brush;
};

#endif // WIDGET_H
