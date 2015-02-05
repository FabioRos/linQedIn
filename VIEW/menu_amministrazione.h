#ifndef MENU_AMMINISTRAZIONE_H
#define MENU_AMMINISTRAZIONE_H

#include "./CONTROLLER/admin_controller.h"
#include "./VIEW/amministrazione.h"


class DB;
class menu_amministrazione : public QWidget{
private:
    Q_OBJECT
    admin_controller* controller;
    QWidget* parent_ptr;
    users_repository* ptr_repo;
    QPushButton* btn_aggiungi_utente, *btn_rimuovi_utente, *btn_cambia_account, *btn_dump_db, *btn_cerca;
    QPushButton* btn_caricamento, *btn2_salvataggio;
    QPushButton* exit;
    QVBoxLayout *main_menu_layout;
    //per esseri sicuri di salvare/caricare
    QMessageBox*sicuro_caricare;
    QErrorMessage* sicuro_salvare;

public:
    menu_amministrazione(admin_controller* ,QWidget* =0,users_repository* =0);
    ~menu_amministrazione();
public slots:
    void conferma_caricamento() ;
    void carica_db_da_file();
    void salva_su_file() const;
signals:
    void refresh_tabella();
};

#endif // MENU_AMMINISTRAZIONE_H
