#include "profilo_popup.h"

void profilo_popup::inizializza(){
    this->setWindowIcon(QIcon("popup_icon.png"));
    std::string cognome=ptr_repository->get_ptr_utente(username_da_visualizzare)->get_cognome();
    std::string nome=ptr_repository->get_ptr_utente(username_da_visualizzare)->get_nome();

    QString Cognome_nome=QString::fromStdString(cognome);
    Cognome_nome.append(" ");
    Cognome_nome.append(QString::fromStdString(nome));

    setWindowTitle(Cognome_nome);


    layout=new QVBoxLayout(this);
    QString txt_titolo="Profilo di \"";
    txt_titolo.append(Cognome_nome);
    txt_titolo.append("\"");
    titolo=new QLabel(txt_titolo);

    informazioni=new client_profilo(ptr_repository,username_da_visualizzare);
    informazioni->modalita_sola_lettura();

    controller= new aggiungi_modifica_utenti(ptr_repository);

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
    btn_rimuovi_dalla_rete=new QPushButton ("Rimuovi Questo utente alla tua rete di contatti");

    layout->addWidget(titolo);
    layout->addWidget(frame_principale);


}

profilo_popup::profilo_popup(users_repository *p_repo, const std::string &usn_corrente,const std::string &usn, QWidget *parent):
    username_da_visualizzare(usn),username_corrente(usn_corrente),ptr_repository(p_repo),QWidget(parent){

    inizializza();

    if(username_corrente!=username_da_visualizzare){
        if(controller->esiste_A_nella_rete_di_B(username_da_visualizzare,username_corrente)){                                       //devo fare l f() delcontroller che verifica collegamento
            layout->addWidget(btn_rimuovi_dalla_rete);
        }else{
            layout->addWidget(btn_aggiungi_a_rete);
        }
        //connessioni
        connect(btn_aggiungi_a_rete,SIGNAL(clicked()),this,SLOT(aggiungi_a_rete()));
        connect(btn_rimuovi_dalla_rete,SIGNAL(clicked()),this,SLOT(rimuovi_dalla_rete()));
    }
}

profilo_popup::profilo_popup(users_repository *p_repo, const std::string &target, QWidget *parent):
    username_da_visualizzare(target),ptr_repository(p_repo),QWidget(parent){

    inizializza();
}


void profilo_popup::aggiungi_a_rete(){
    controller->aggiungi_A_alla_rete_di_B(username_da_visualizzare,username_corrente);
    QLabel* lbl_aggiunto=new QLabel("<center><h4>utente aggiunto con successo<br />alla tua rete di contatti.</h4></center>");
    lbl_aggiunto->setStyleSheet("color:\"green\";");
    lbl_aggiunto->setGeometry(400,300,250,100);
    lbl_aggiunto->show();
    this->close();

}

void profilo_popup::rimuovi_dalla_rete(){
   controller->rimuovi_A_alla_rete_di_B(username_da_visualizzare,username_corrente);
   QLabel* lbl_rimosso=new QLabel("<center><h4>utente rimosso con successo<br />dalla tua rete di contatti.</h4></center>");
   lbl_rimosso->setStyleSheet("color:\"green\";");
   lbl_rimosso->setGeometry(400,300,250,100);
   lbl_rimosso->show();
   this->close();
}
