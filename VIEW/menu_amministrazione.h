#ifndef MENU_AMMINISTRAZIONE_H
#define MENU_AMMINISTRAZIONE_H

#include <QWidget>
#include <QPushButton>
class menu_amministrazione : public QWidget{
private:
    Q_OBJECT
    QPushButton* btn_aggiungi_utente, *btn_rimuovi_utente, *btn_cambia_account, *btn_dump_db, *btn_cerca;
public:
    menu_amministrazione(QWidget* =0);
};

#endif // MENU_AMMINISTRAZIONE_H
