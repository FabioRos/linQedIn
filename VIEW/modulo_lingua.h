#ifndef MODULO_LINGUA_H
#define MODULO_LINGUA_H

#include <QWidget>
#include <QListWidget>
#include <QComboBox>
#include <QPushButton>

class modulo_lingua : public QWidget{
private:
    QListWidget* lingue;
    Q_OBJECT
    QLineEdit* descrizione_lingua;
    QComboBox *select_parlato, *select_scritto, *select_comprensione;
    QPushButton* btn_rimuovi_lingua, *inserisci_lingua;
public:
    explicit modulo_lingua(QWidget *parent = 0);
    std::list<std::string> get_lista_lingue() const;
    ~modulo_lingua();
signals:
    void segnale_err_txt();
public slots:
     void controllore();
     void errore_testo_vuoto();
     void aggiungi_lingua();
     void rimuovi_lingua();

};

#endif // MODULO_LINGUA_H
