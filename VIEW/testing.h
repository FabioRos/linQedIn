#ifndef TESTING_H
#define TESTING_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

class testing: public QWidget{
private:
    Q_OBJECT
    QVBoxLayout* layout;
    QLabel* esito_testuale;
    QPushButton* chiudi_finestra;
public:
    testing(QWidget* =0);
    ~testing();
    void run_tests();
};
#endif // TESTING_H
