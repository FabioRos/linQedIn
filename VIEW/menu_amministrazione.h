#ifndef MENU_AMMINISTRAZIONE_H
#define MENU_AMMINISTRAZIONE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QErrorMessage>
class menu_amministrazione : public QWidget{
private:
    Q_OBJECT
    QPushButton* btn_aggiungi_utente, *btn_rimuovi_utente, *btn_cambia_account, *btn_dump_db, *btn_cerca;
    QPushButton* btn1, *btn2;
    QPushButton* exit;
    QVBoxLayout *main_menu_layout;
    QHBoxLayout *layout_I_O;
    //per esseri sicuri di salvare/caricare
    QMessageBox*sicuro_caricare;
    QErrorMessage* sicuro_salvare;
public:
    menu_amministrazione(QWidget* =0);
};

#endif // MENU_AMMINISTRAZIONE_H
