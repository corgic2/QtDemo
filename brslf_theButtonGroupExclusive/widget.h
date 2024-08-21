#ifndef WIDGET_H
#define WIDGET_H
#include <QButtonGroup>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void LineEditStyleSheet();
    void LineEdit2StyleSheet();
    void SlotButtonClicked(int cnt);
private:
    Ui::Widget *ui;
    QButtonGroup* m_buttonGroup = nullptr;
};

#endif // WIDGET_H
