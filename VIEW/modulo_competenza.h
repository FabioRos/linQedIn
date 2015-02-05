#ifndef MODULO_COMPETENZA_H
#define MODULO_COMPETENZA_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>

class modulo_competenza : public QWidget{
private:
    QPushButton *btn_nuova_competenza, *btn_rimuovi_competenze;
   QListWidget* competenze;
   QLineEdit *txt_nuova_competenza;
    Q_OBJECT
public:
    explicit modulo_competenza(QWidget *parent = 0);
    std::list<std::string> get_lista_competenze() const; // da testare
    ~modulo_competenza();
signals:
   void segnale_err_txt();
public slots:
   void controllore();
   void errore_testo_vuoto();
    void aggiungi_competenza();
    void rimuovi_competenza();
};

#endif // MODULO_COMPETENZA_H
