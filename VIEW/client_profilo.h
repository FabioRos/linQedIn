#ifndef CLIENT_PROFILO_H
#define CLIENT_PROFILO_H
#include "./MODEL/users_repository.h"
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class client_profilo : public QWidget{
    Q_OBJECT
private:
    users_repository* ptr_repository;
    std::string username_;
    QGridLayout* layout_top;
    int riga_inizio_competenze, numero_competenze;
    void disabilita_tutto();
    void abilita_tutto();
    void disabilita_competenze(const bool& value);
public:
    explicit client_profilo(users_repository* , const std::string& username ,QWidget *parent = 0);
    QLineEdit* nome,*cognome,*username;
    QPushButton* btn_modifica_profilo, *btn_salva_modifiche;
    QLabel* tipo_account, *lbl_tipo_account,*lbl_username,*lbl_cognome,*lbl_nome,*lbl_competenze;
signals:

public slots:
    void abilita_modifiche();
    void salva_modifiche();

};

#endif // CLIENT_PROFILO_H
