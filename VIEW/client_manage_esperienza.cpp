#include "client_manage_esperienza.h"


client_manage_esperienza::client_manage_esperienza(users_repository* ptr_repo, const std::string& usn, QWidget *parent):
    ptr_repository(ptr_repo),username_corrente(usn), QWidget(parent){
    aggiungi_controlli_esperienza_professionale();
    connect(btn_inserisci_esperienza,SIGNAL(clicked()),this, SLOT(aggiungi_esperienza()));
}

void client_manage_esperienza::aggiungi_controlli_esperienza_professionale(){
    layout_top= new QGridLayout(this);
    int riga_corrente=3;


    //Titolo
    layout_top->addWidget(new QLabel("<center><h3>Aggiunta Esperienze Professionali</h3></center> "),riga_corrente++,1,1,3);
    //Azienda
    layout_top->addWidget(new QLabel("azienda: "),riga_corrente,1);
    input_nuova_azienda = new QLineEdit;
    input_nuova_azienda->setPlaceholderText("Nome azienda");
    layout_top->addWidget(input_nuova_azienda,riga_corrente++,2,1,2);
    //Posizione
    layout_top->addWidget(new QLabel("posizione: "),riga_corrente,1);
    input_nuova_posizione = new QLineEdit;
    input_nuova_posizione->setPlaceholderText("Ruolo ricoperto");
    layout_top->addWidget(input_nuova_posizione,riga_corrente++,2,1,2);
    //Luogo
    layout_top->addWidget(new QLabel("luogo: "),riga_corrente,1);
    input_nuovo_luogo = new QLineEdit;
    input_nuovo_luogo->setPlaceholderText("Indirizzo o Città");
    layout_top->addWidget(input_nuovo_luogo,riga_corrente++,2,1,2);
    //Descrizione
    layout_top->addWidget(new QLabel("descrizione: "),riga_corrente,1);
    input_nuova_descrizione=new QTextEdit;
    input_nuova_descrizione->setMinimumHeight(300);
    input_nuova_descrizione->setPlaceholderText("Parla qui di quello che hai fatto ed imparato nell'esperienza!");
    layout_top->addWidget(input_nuova_descrizione,riga_corrente++,2,1,2);

    //Data inizio
    layout_top->addWidget(new QLabel("Da: "),riga_corrente++,1);
    cal_data_inizio= new QCalendarWidget;
    layout_top->addWidget(cal_data_inizio,riga_corrente++,1,1,3);
    //Data fine
    layout_top->addWidget(new QLabel("A: "),riga_corrente++,1);
    cal_data_fine= new QCalendarWidget;
    layout_top->addWidget(cal_data_fine,riga_corrente++,1,1,3);
    //bottone inserimento
    btn_inserisci_esperienza=new QPushButton("Inserisci esperienza");
    layout_top->addWidget(btn_inserisci_esperienza,riga_corrente,1,1,3);
}



void client_manage_esperienza::aggiungi_esperienza(){
    edit_controller=new aggiungi_modifica_utenti(ptr_repository);
    edit_controller->aggiungi_esperienza(username_corrente,
                                         input_nuova_azienda->text().toStdString(),
                                         input_nuova_posizione->text().toStdString(),
                                         input_nuovo_luogo->text().toStdString(),
                                         input_nuova_descrizione->toPlainText().toStdString(),
                                         cal_data_inizio->selectedDate().toString("d-M-yyyy").toStdString(),
                                         cal_data_fine->selectedDate().toString("d-M-yyyy").toStdString());
   // std::cout<< "\n[[[" <<cal_data_inizio->selectedDate().toString("d-M-yyyy").toStdString()<<"]]]\n";
}

void client_manage_esperienza::messaggio_conferma(){

}
