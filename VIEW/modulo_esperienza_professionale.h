#ifndef MODULO_ESPERIENZA_PROFESSIONALE_H
#define MODULO_ESPERIENZA_PROFESSIONALE_H

#include <QWidget>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QPushButton>
#include <QListWidget>

class modulo_esperienza_professionale : public QWidget{
private:
    Q_OBJECT
    QLineEdit* luogo, *descrizione, *nome_azienda, *posizione;
    QCalendarWidget* data_inizio, *data_fine;
    QPushButton* btn_inserisci_esperienza, *btn_rimuovi_esperienza;
    QListWidget* esperienze;
public:
    explicit modulo_esperienza_professionale(QWidget *parent = 0);
    std::list<std::string> get_lista_esperienze_txt() const;// da fare
signals:
    void segnale_err_txt();
public slots:
    void controllore();
    void errore_testo_vuoto();
    void aggiungi_esperienza();
    void rimuovi_esperienza();
};

#endif // MODULO_ESPERIENZA_PROFESSIONALE_H
