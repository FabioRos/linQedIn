#ifndef MODULO_LINGUA_H
#define MODULO_LINGUA_H

#include <QWidget>
#include <QListWidget>
#include <QComboBox>

class modulo_lingua : public QWidget{
private:
     QListWidget* lingue;
    Q_OBJECT
     QLineEdit* descrizione_lingua;
     QComboBox *select_parlato, *select_scritto, *select_comprensione;
public:
    explicit modulo_lingua(QWidget *parent = 0);

signals:

public slots:
     void aggiungi_lingua();
     void rimuovi_lingua();

};

#endif // MODULO_LINGUA_H
