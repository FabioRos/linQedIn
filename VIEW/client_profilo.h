#ifndef CLIENT_PROFILO_H
#define CLIENT_PROFILO_H
#include "./MODEL/users_repository.h"
#include "./CONTROLLER/client_controller.h"
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>
class client_profilo : public QWidget{
    Q_OBJECT
private:
    QScrollArea* ptr_scroll_area_contenitore;
    users_repository* ptr_repository;
    std::string username_;
    QGridLayout* layout_top;
    int riga_inizio_competenze, numero_competenze,riga_fine_competenze;
    void disabilita_tutto();
    void abilita_tutto();
    void abilita_disabilita_competenze(const bool& value);

    void popola();
    void popola_blocco_competenze();


public:
    client_controller* c_controller;
    explicit client_profilo(users_repository* , QScrollArea*, const std::string& username ,QWidget *parent = 0);
    QLineEdit* nome,*cognome,*username, *nuova_competenza;
    QPushButton* btn_modifica_profilo, *btn_salva_modifiche, *btn_aggiungi_competenza;
    QLabel* tipo_account, *lbl_tipo_account,*lbl_username,*lbl_cognome,*lbl_nome;
    QLabel *lbl_competenze, *lbl_hint_inserimento;
signals:

public slots:
    void abilita_modifiche();
    void salva_modifiche();
    void aggiungi_competenza();

};

#endif // CLIENT_PROFILO_H
