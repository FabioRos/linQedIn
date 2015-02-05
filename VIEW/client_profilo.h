#ifndef CLIENT_PROFILO_H
#define CLIENT_PROFILO_H
#include "./CONTROLLER/client_controller.h"

#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>
#include <QComboBox>
#include <QTextEdit>
#include <QCalendarWidget>

#include <QLayoutItem>
#include <sstream>
#include <istream>
#include <QMessageBox>


class client_profilo : public QWidget{
    Q_OBJECT
private:
    QScrollArea* ptr_scroll_area_contenitore;
    users_repository* ptr_repository;
    std::string username_;
    QGridLayout* layout_top;
    int riga_inizio_competenze, numero_competenze,riga_fine_competenze,numero_lingue;
    int riga_inizio_esperienze_professionali,numero_esperienze_professionali;
    int riga_inizio_inserimento_lingua,riga_fine_esperienze_profesionali,riga_ultima_lingua;
    void disabilita_tutto();
    void abilita_tutto();
    void disabilita_competenze(const bool& value =true);  //true_disabilita
    //max 12 competenze per le quali ho lasciato 4 righe di spazio.
    void disabilita_lingue(const bool& value =true);
    //max altre 3 lingue per le quali ho lasciato 9 righe di spazio.
    void disabilita_esperienze_professionali(const bool& value =true);

    void popola();
    void inizializza(const std::list<std::string>&);
    void inizializza_lingue(const std::list<std::string>&,std::list<std::string>::const_iterator& ,int&);
    void inizializza_competenze(const std::list<std::string>&,std::list<std::string>::const_iterator& ,int&);
    void inizializza_esperienze(const std::list<std::string>&,std::list<std::string>::const_iterator& ,int&);
    void disabilita_controlli_inserimento(const bool&);
    void aggiungi_controlli_lingua(int& riga_corrente);
    void aggiungi_controlli_esperienza_professionale(int& riga_corrente);
    void disabilita_controlli_lingua(const bool & b);
    void disabilita_controlli_competenze(const bool & b);
    void disabilita_controlli_esperienze_professionali(const bool & b);

    //Widgets
    QLineEdit* nome,*cognome,*username, *nuova_competenza,*nuova_descrizione_lingua;
    QPushButton* btn_modifica_profilo, *btn_salva_modifiche, *btn_aggiungi_competenza;
    QPushButton* btn_aggiungi_lingua,*btn_inserisci_esperienza;
    QLabel* tipo_account, *lbl_tipo_account,*lbl_username,*lbl_cognome,*lbl_nome;
    QLabel *lbl_competenze, *lbl_hint_inserimento, *lbl_inserimento_lingua;
    QStringList livelli;
    QComboBox* nuovo_livello_comprensione, *nuovo_livello_parlato,*nuovo_livello_scritto;
    QLabel* lbl_esp_nuova_azienda,*lbl_esp_nuova_posizione,*lbl_esp_nuovo_luogo;
    QLabel* lbl_esp_nuova_descrizione,*lbl_esp_nuova_data_inizio,*lbl_esp_nuova_data_fine;
    QLineEdit *input_nuova_azienda, *input_nuova_posizione, *input_nuovo_luogo;
    QTextEdit *input_nuova_descrizione;
    QCalendarWidget* cal_data_inizio, *cal_data_fine;


public:
    client_controller* c_controller;
    explicit client_profilo(users_repository* , QScrollArea*, const std::string& username ,QWidget *parent = 0);

signals:

public slots:
    void abilita_modifiche();
    void salva_modifiche();
    void aggiungi_competenza();
    void aggiungi_lingua();

};
#endif // CLIENT_PROFILO_H
