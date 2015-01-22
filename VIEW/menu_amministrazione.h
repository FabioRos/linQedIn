#ifndef MENU_AMMINISTRAZIONE_H
#define MENU_AMMINISTRAZIONE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QErrorMessage>
#include "./MODEL/users_repository.h"

class DB;
class menu_amministrazione : public QWidget{
private:
    Q_OBJECT
    QPushButton* btn_aggiungi_utente, *btn_rimuovi_utente, *btn_cambia_account, *btn_dump_db, *btn_cerca;
    QPushButton* btn_caricamento, *btn2_salvataggio;
    QPushButton* exit;
    QVBoxLayout *main_menu_layout;
    //per esseri sicuri di salvare/caricare
    QMessageBox*sicuro_caricare;
    QErrorMessage* sicuro_salvare;
    users_repository* ptr_repo;
    QWidget* parent_ptr;
public:
    menu_amministrazione(QWidget* =0,users_repository* =0);
public slots:
    void conferma_caricamento() ;
    void carica_db_da_file();
    void salva_su_file() const;
signals:
    void refresh_tabella();
};

#endif // MENU_AMMINISTRAZIONE_H
