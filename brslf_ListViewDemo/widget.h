#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListView>
#include <QStandardItemModel>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void SlotItemChanged(QStandardItem *item);
    void ChangeItemStyle(QStandardItem *item, bool checked);
private:
    Ui::Widget *ui;
    QListView * m_listView = nullptr;
    QStandardItemModel* m_itemModel = nullptr;
    QFont m_font;
};

#endif // WIDGET_H
