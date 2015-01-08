#ifndef MENU_BAR_H
#define MENU_BAR_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QMessageBox>

class menu_bar : public QWidget{
private:
    Q_OBJECT
    QPushButton* btn_profilo, *btn_rete, *btn_log_out, *btn_cerca;
    QVBoxLayout* layout_menu;
public:
    menu_bar(QWidget* parent =0);
public slots:
    void log_out();
};

#endif // MENU_BAR_H
