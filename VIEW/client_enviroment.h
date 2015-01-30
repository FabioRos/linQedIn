#ifndef MENU_BAR_H
#define MENU_BAR_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QScrollArea>
#include "./MODEL/users_repository.h"
#include "./VIEW/client_profilo.h"
class client_enviroment : public QWidget{
private:
    Q_OBJECT
    QPushButton* btn_profilo, *btn_rete, *btn_log_out, *btn_cerca;
    QHBoxLayout* layout_due_colonne;
    QVBoxLayout* layout_menu;
    QScrollArea* scroll_area;
    users_repository* ptr_repository;
    std::string username_corrente;
    client_profilo* pagina_profilo;
public:
    client_enviroment(users_repository* , const std::string& utente_corrente, QWidget* parent =0);
    ~client_enviroment();
public slots:
    void log_out();
    void mostra_profilo();
};

#endif // MENU_BAR_H
