#ifndef AMMINISTAZIONE_H
#define AMMINISTAZIONE_H
#include <QtWidgets>
#include <QLayout>

class amministazione: public QWidget
{private:
    Q_OBJECT
    QPushButton* btn1, *btn2;
    QPushButton* exit;
    QHBoxLayout *layout;
    //per esseri sicuri di salvare/caricare
    QMessageBox*sicuro_caricare;
    QErrorMessage* sicuro_salvare;
public:
    amministazione(QWidget* =0);    //QWidget* =0 sempre
};

#endif // AMMINISTAZIONE_H
