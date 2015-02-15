#include "popup_rimuovi_utente_da_rete.h"

popup_rimuovi_utente_da_rete::popup_rimuovi_utente_da_rete(const std::string &usn,
    const std::string &target, users_repository *ptr_repo, QWidget *parent):
    username_corrente(usn),username_da_rimuovere(target),ptr_repository(ptr_repo),
    QWidget(parent){
    QString s=("<center><i>Vuoi davvero rimuovere l\'utente<br /> \"");
    s.append(QString::fromStdString(username_da_rimuovere));
    s.append("\"<br />dalla tua rete di contatti?<br /></i></center>");


    testo= new QLabel(s);
    //testo->setStyleSheet();
    layout=new QVBoxLayout(this);
    layout->addWidget(testo);

    btn_annulla=new QPushButton("NO");
    btn_conferma=new QPushButton("SI");
    layout_bottoni= new QHBoxLayout;
    layout_bottoni->addWidget(btn_annulla);
    layout_bottoni->addWidget(btn_conferma);
    layout->addLayout(layout_bottoni);



    //connessioni
    connect(btn_annulla,SIGNAL(clicked()),this,SLOT(close()));
    connect(btn_conferma,SIGNAL(clicked()),this,SLOT(rimuovi_da_rete()));

}

void popup_rimuovi_utente_da_rete::rimuovi_da_rete(){
    aggiungi_modifica_utenti* controller=new aggiungi_modifica_utenti(ptr_repository);
    controller->rimuovi_A_alla_rete_di_B(username_da_rimuovere,username_corrente);
    rimosso_con_successo();
    this->close();
}

void popup_rimuovi_utente_da_rete::rimosso_con_successo(){
    QString testo("<center><i>L'utente </i><b>\"");
    testo.append(QString::fromStdString(username_da_rimuovere));
    testo.append("\"</b> <br />è stato rimosso con successo <br />dai tuoi contatti.");
    QMessageBox* msg= new QMessageBox(QMessageBox::Information,"Conferma Rimozione",testo);
    msg->show();
}
