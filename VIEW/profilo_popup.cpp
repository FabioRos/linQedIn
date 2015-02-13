#include "profilo_popup.h"

profilo_popup::profilo_popup(users_repository *p_repo, const std::string &usn_corrente,const std::string &usn, QWidget *parent):
    username_da_visualizzare(usn),username_corrente(usn_corrente),ptr_repository(p_repo),QWidget(parent){

    std::string cognome=ptr_repository->get_ptr_utente(username_da_visualizzare)->get_cognome();
    std::string nome=ptr_repository->get_ptr_utente(username_da_visualizzare)->get_nome();

    QString Cognome_nome=QString::fromStdString(cognome);
    Cognome_nome.append(" ");
    Cognome_nome.append(QString::fromStdString(nome));

    setWindowTitle(Cognome_nome);


    QVBoxLayout* layout=new QVBoxLayout(this);
    QString txt_titolo="Profilo di \"";
    txt_titolo.append(Cognome_nome);
    txt_titolo.append("\"");
    titolo=new QLabel(txt_titolo);

    informazioni=new client_profilo(ptr_repository,username_da_visualizzare);
    informazioni->modalita_sola_lettura();

    //scroll_Area
    frame_principale=new QScrollArea(this);
    frame_principale->setHorizontalScrollBarPolicy( Qt::ScrollBarAsNeeded);
    frame_principale->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn);
    frame_principale->setWidgetResizable(true);
    frame_principale->setFrameStyle(QFrame::NoFrame);
    frame_principale->setMaximumHeight(530);
    frame_principale->setMinimumHeight(530);

    frame_principale->setWidget(informazioni);

    btn_aggiungi_a_rete=new QPushButton ("Aggiungi Questo utente alla tua rete di contatti");

    layout->addWidget(titolo);
    layout->addWidget(frame_principale);
    layout->addWidget(btn_aggiungi_a_rete);

    //connessioni
    connect(btn_aggiungi_a_rete,SIGNAL(clicked()),this,SLOT(aggiungi_a_rete()));

}


void profilo_popup::aggiungi_a_rete(){
    aggiungi_modifica_utenti* controller= new aggiungi_modifica_utenti(ptr_repository);
    controller->aggiungi_A_alla_rete_di_B(username_da_visualizzare,username_corrente);

}
