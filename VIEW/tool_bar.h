#ifndef TOOL_BAR_H
#define TOOL_BAR_H

#include "./CONTROLLER/admin_controller.h"

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>

class tool_bar : public QWidget
{private:
    Q_OBJECT
    QHBoxLayout *layout_toolbar;
    QPushButton *btn_exit;
    admin_controller* controller;

public:
    explicit tool_bar(users_repository* ,QWidget *parent = 0);
    ~tool_bar();
signals:

public slots:
    void chiudi();

};

#endif // TOOL_BAR_H
