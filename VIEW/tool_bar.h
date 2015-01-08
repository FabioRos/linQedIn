#ifndef TOOL_BAR_H
#define TOOL_BAR_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>

class tool_bar : public QWidget
{private:
    Q_OBJECT
    QHBoxLayout *layout_toolbar;
    QPushButton *btn_exit;

public:
    explicit tool_bar(QWidget *parent = 0);

signals:

public slots:
    void chiudi();

};

#endif // TOOL_BAR_H
