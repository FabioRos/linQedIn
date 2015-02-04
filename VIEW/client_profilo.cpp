#include "client_profilo.h"
#include <QLayoutItem>
#include <sstream>
#include <istream>
#include <QMessageBox>


#include <iostream>

client_profilo::client_profilo(users_repository* repo, QScrollArea* s_a, const std::string& user, QWidget *parent) :
    QWidget(parent), ptr_repository(repo), username_(user),ptr_scroll_area_contenitore(s_a){
    //ptr_scroll_area_contenitore->widgetResizable(true);
    popola();

    // Installazione
    c_controller= new client_controller(ptr_repository);

    std::list<std::string> user_data = c_controller->get_info_utente(username_);

    //    std::list<std::string>::const_iterator itt=user_data.begin();
    //    for(;itt!=user_data.end();++itt)
    //        std::cout<<*itt;

    inizializza(user_data);
    //di default disabilitati, li abilito per la modifica.
    disabilita_tutto();
    //connessioni
    connect(btn_modifica_profilo,SIGNAL(clicked()),this,SLOT(abilita_modifiche()));
    connect(btn_salva_modifiche,SIGNAL(clicked()),this,SLOT(salva_modifiche()));
    connect(btn_aggiungi_competenza,SIGNAL(clicked()),this,SLOT(aggiungi_competenza()));

}
void client_profilo::abilita_modifiche(){
    abilita_tutto();
    btn_modifica_profilo->hide();
    btn_salva_modifiche->show();
    layout_top->removeWidget(btn_modifica_profilo);
    layout_top->addWidget(btn_salva_modifiche,1,3);

    disabilita_controlli_inserimento(false);
}
void client_profilo::salva_modifiche(){
    disabilita_tutto();
    btn_modifica_profilo->show();
    btn_salva_modifiche->hide();
    //salva
    layout_top->removeWidget(btn_salva_modifiche);
    layout_top->addWidget(btn_modifica_profilo,1,3);


    disabilita_controlli_inserimento(true);


}
void client_profilo::aggiungi_competenza(){
    lbl_hint_inserimento->hide();
    //controllo che non ci sia già
   // if(nuova_competenza->text().toStdString())

    if( numero_competenze<18){
        if(nuova_competenza->text()!=""){
            if(numero_competenze%3==0){  //righe piene, ne devo aggiungere una
                if(!numero_competenze)riga_inizio_competenze++;

                riga_fine_competenze++;
            }
            layout_top->addWidget(new QLineEdit(nuova_competenza->text()),
                                  riga_inizio_competenze+numero_competenze/3,
                                  (numero_competenze%3)+1);
            ++numero_competenze;
            //refresh
            disabilita_tutto();
            abilita_modifiche();
        }else{
            QMessageBox* msg_vuoto= new QMessageBox(QMessageBox::Information,"Campo vuoto",
                                                    "Non puoi inserire competenze senza una descrizione.");
            msg_vuoto->show();
        }

    }else{
        QMessageBox* msg= new QMessageBox(QMessageBox::Information,"Numero massimo competenze raggiunto",
                                          "Hai raggiunto il numero massimo di competenze fissato a 18.");
        msg->show();
        nuova_competenza->hide();
        btn_aggiungi_competenza->hide();
    }

}
void client_profilo::disabilita_tutto(){    //eccetto tasto btn_modifica_profilo
    nome->setDisabled(true);
    cognome->setDisabled(true);;
    username->setDisabled(true);
    //competenze
    disabilita_competenze(true);
    disabilita_lingue(true);
    disabilita_esperienze_professionali(true);


}
void client_profilo::abilita_tutto(){
    nome->setDisabled(false);
    cognome->setDisabled(false);
    username->setDisabled(false);
    //competenze
    disabilita_competenze(false);
    disabilita_lingue(false);
    disabilita_esperienze_professionali(false);


    //layout_top->itemAtPosition(r,c)
}
void client_profilo::disabilita_competenze(const bool &value){
    //per recuperare i widgets mi conviene usare
    //"QLayoutItem * QGridLayout::itemAtPosition ( int row, int column ) const"
    int r=riga_inizio_competenze;
    if(value==false){
        lbl_hint_inserimento=new QLabel("Per eliminare una voce cancellare il suo contenuto.");
        lbl_hint_inserimento->setStyleSheet(QString("font-style: italic;"));
        layout_top->addWidget(lbl_hint_inserimento,0,1,1,3);
    }else{
        if (lbl_hint_inserimento!=0){
            layout_top->removeWidget(lbl_hint_inserimento);
        }
    }
    /*
        algoritmo:
            es r=4:, numero_competenze=8
            mi servono: (4,1),(4,2),(4,3),(5,1),(5,2),(5,3),(6,1),(6,2)
    */
    int numero_iterazioni=numero_competenze+static_cast<int>(numero_competenze/4+1)+1;
    bool prima_volta=true;
    //std::cout<< "num_competenze: "<<numero_competenze<<std::endl;
    if(numero_competenze){
        for(int i=0;i<numero_iterazioni;i++){
            if(i%4==0){
                if(!prima_volta)
                    r+=1;
                else
                    prima_volta=false;
            }else{
                //!!MODO PER PRENDERSI WIDGETS ANONIMI DAL LAYOUT!!
                //std::cout<<"("<<r<<","<<i%4<<")   ";
                if(layout_top->itemAtPosition(r,i%4))
                    layout_top->itemAtPosition(r,i%4)->widget()->setDisabled(value);

            }
        }
    }

}
void client_profilo::disabilita_lingue(const bool &value){//true disabilita
    int r_c=riga_fine_competenze+4;     // 4 sono quelle di lasco per
                                        // inserire fino a 18 competenze
    if(numero_lingue){
        for(int i=1;i<=numero_lingue;i++){
            layout_top->itemAtPosition(r_c+(4*i),1)->widget()->setDisabled(value);
            for(int j=-1;j<2;j++){
                if(layout_top->itemAtPosition(r_c+(4*i)+j,3)){
                    layout_top->itemAtPosition(r_c+(4*i)+j,3)->widget()->setDisabled(value);
                }
            }
        }
    }
}
void client_profilo::disabilita_esperienze_professionali(const bool &value){
    int r_c=riga_inizio_esperienze_professionali;//inizia giusto! il problema è sul conteggio
    if(numero_esperienze_professionali){
        //std::cout<<numero_esperienze_professionali;
        for(int i=0;i<numero_esperienze_professionali;i++){
            for (int j=0;j<7;j++){
                layout_top->itemAtPosition(r_c+(7*i+1)+j,2)->widget()->setDisabled(value);
            }
        }
    }
}


void client_profilo::popola() {
    //inizializzo, importante farlo qui!
    numero_competenze=0;
    numero_lingue=0;
    
    btn_modifica_profilo =new QPushButton("Modifica Profilo");
    btn_salva_modifiche= new QPushButton("Salva modifiche");
    layout_top=new QGridLayout(this);
    nome=new QLineEdit("");
    cognome=new QLineEdit("");
    username=new QLineEdit("");
    lbl_tipo_account=new QLabel("Tipo Account: ");
    lbl_tipo_account->setStyleSheet(QString("font-weight:bold;"));
    tipo_account=new QLabel();
    tipo_account->setStyleSheet(QString("color:blue;"));
    lbl_username=new QLabel("Username: ");
    lbl_username->setStyleSheet(QString("font-weight:bold;"));
    lbl_cognome=new QLabel("Cognome: ");
    lbl_cognome->setStyleSheet(QString("font-weight:bold;"));
    lbl_nome=new QLabel("Nome: ");
    lbl_nome->setStyleSheet(QString("font-weight:bold;"));
    lbl_competenze=new QLabel("Competenze: ");
    lbl_competenze->setStyleSheet(QString("font-weight:bold;"));

    //aggiungo al layout

    layout_top->addWidget(lbl_nome,1,0);
    layout_top->addWidget(nome,1,1,1,2);
    layout_top->addWidget(lbl_cognome,2,0);
    layout_top->addWidget(cognome,2,1,1,2);
    layout_top->addWidget(lbl_username,3,0);
    layout_top->addWidget(username,3,1,1,2);
    layout_top->addWidget(btn_modifica_profilo,1,3);
    layout_top->addWidget(lbl_tipo_account,4,0);


    layout_top->addWidget(tipo_account,4,1);
    layout_top->addWidget(lbl_competenze,5,0);

    btn_aggiungi_competenza=new QPushButton("aggiungi");
    nuova_competenza= new QLineEdit("");
}

void client_profilo::inizializza(const std::list<std::string>& user_data){
    std::list<std::string>::const_iterator it=user_data.begin();
    if(it!=user_data.end()) {
        //*it := tipo account
        tipo_account->setText(QString::fromStdString(*it));
    }
    ++it;
    if(it!=user_data.end()) {
        //username
        username->setText(QString::fromStdString(*it));
    }
    ++it;
    if(it!=user_data.end()) {
        //cognome
        cognome->setText(QString::fromStdString(*it));
    }
    ++it;
    if(it!=user_data.end()) {
        //nome
        nome->setText(QString::fromStdString(*it));
    }
    ++it;

    riga_inizio_competenze=5;
    int indice_riga=riga_inizio_competenze;
    inizializza_competenze(user_data,it,indice_riga);
    //qui devo inserire dalla riga "indice_riga+2" //per bottone e lbl_hint
    indice_riga+=2;

    //LINGUE
    ++it;
    inizializza_lingue(user_data,it,indice_riga);


    /*
        Da aggiungere metodi inserimento lingua
    */

    //ESPERIENZE PROFESSIONALI
    ++it;
    inizializza_esperienze(user_data,it,indice_riga);


}


void client_profilo::inizializza_lingue(const std::list<std::string> &user_data,
                                        std::list<std::string>::const_iterator& it, int &indice_riga){


    livelli << "A1" << "A2" << "B1" << "B2"<< "C1" << "C2";
    if(it!=user_data.end() && *it=="#inizio_lingue#"){
        ++it;
        indice_riga+=4;    // cosi mi tengo lo spazio per inserire altre 12 competenze
        QLabel* lbl_lingue = new QLabel("Lingue: ");
        lbl_lingue->setStyleSheet("font-weight:bold;");
        layout_top->addWidget(lbl_lingue,indice_riga++,0);

        //std::cout<<"[[["<<indice_riga<<"]]]";
        for(;it!=user_data.end() && *it != "#fine_lingue#";++it){
            numero_lingue++;
            std::string descrizione_, l_comprensione,l_parlato_,l_scritto_,s=*it;

            std::string delimiter = "#";
            size_t pos = 0;

            pos = s.find(delimiter);
            descrizione_ = s.substr(0,s.find(delimiter));
            s.erase(0, pos + delimiter.length());
            pos = s.find(delimiter);
            l_comprensione = s.substr(0,s.find(delimiter));
            s.erase(0, pos + delimiter.length());
            l_parlato_ = s.substr(0,s.find(delimiter));
            s.erase(0, pos + delimiter.length());
            l_scritto_=s;
            //std::cout<<descrizione_<<l_comprensione<<l_parlato_<<l_scritto_;

            QComboBox *select_comprensione, *select_parlato,*select_scritto;
            select_comprensione=new QComboBox();
            select_parlato=new QComboBox();;
            select_scritto=new QComboBox();


            select_comprensione->addItems(livelli);
            select_parlato->addItems(livelli);
            select_scritto->addItems(livelli);


            select_comprensione->setCurrentText(QString::fromStdString(l_comprensione));
            select_parlato->setCurrentText(QString::fromStdString(l_parlato_));
            select_scritto->setCurrentText(QString::fromStdString(l_scritto_));




            layout_top->addWidget(new QLineEdit(QString::fromStdString(descrizione_)),
                                  indice_riga,1,3,1);
            layout_top->addWidget(new QLabel("comprensione: "),indice_riga,2);
            layout_top->addWidget(select_comprensione, indice_riga,3);
            layout_top->addWidget(new QLabel("parlato: "),indice_riga+1,2);
            layout_top->addWidget(select_parlato, indice_riga+1,3);
            layout_top->addWidget(new QLabel("scritto: "),indice_riga+2,2);
            layout_top->addWidget(select_scritto, indice_riga+2,3);
            layout_top->addWidget(new QLabel("<hr>"),indice_riga+3,1,1,3);
            indice_riga+=4;
        }
        indice_riga+=9; // cosi mi tengo lo spazio per inserire altre 3 lingue

        aggiungi_controlli_lingua(indice_riga);
        disabilita_controlli_lingua(true);


        riga_inizio_esperienze_professionali=indice_riga+1;

    }
}

void client_profilo::inizializza_competenze(const std::list<std::string> &user_data,
                                            std::list<std::string>::const_iterator& it, int &indice_riga){


    if(it!=user_data.end()) {
        //competenze
        numero_competenze=0;
        int indice_colonna=0;
        for(;it!=user_data.end() && *it != "#fine_competenze#" ;++it){
            numero_competenze++;    // mi serve per il calcolo degli indici
            QLineEdit* item= new QLineEdit(QString::fromStdString(*it));
            item->setDisabled(true);
            indice_colonna++;
            if(indice_colonna%4==0){
                indice_riga++;
                indice_colonna++;   //così ne metto sempre 3 lasciando il primo posto libero.
            }
            layout_top->addWidget(item,indice_riga,indice_colonna%4);
        }

        riga_fine_competenze=indice_riga;
    }




}

void client_profilo::inizializza_esperienze(const std::list<std::string> &user_data,
                          std::list<std::string>::const_iterator& it, int &indice_riga){

    numero_esperienze_professionali=0;
    if(it!=user_data.end() && *it=="#inizio_esperienze_professionali#"){
        ++it;

        riga_inizio_esperienze_professionali=indice_riga;
        QLabel* lbl_esperienze = new QLabel("Esperienze\nProfessionali: ");
        lbl_esperienze->setStyleSheet("font-weight:bold;");
        layout_top->addWidget(lbl_esperienze,indice_riga++,0);

        //------------------------------------------------------

        for(;it!=user_data.end() && *it != "#fine_esperienze_professionali#";++it){
            numero_esperienze_professionali++;
            // nome_azienda#posizione#luogo#descrizione#data_inizio#data_fine

            std::string nome_azienda_,posizione_,luogo_,descrizione_;
            std::string data_inizio_,data_fine_,s=*it;




            std::string delimiter = "#";
            size_t pos = 0;

            //nome azienda
            pos = s.find(delimiter);
            nome_azienda_ = s.substr(0,s.find(delimiter));
            s.erase(0, pos + delimiter.length());
            //posizione
            pos = s.find(delimiter);
            posizione_ = s.substr(0,s.find(delimiter));
            s.erase(0, pos + delimiter.length());
            //luogo
            pos = s.find(delimiter);
            luogo_ = s.substr(0,s.find(delimiter));
            s.erase(0, pos + delimiter.length());
            //descrizione
            pos = s.find(delimiter);
            descrizione_ = s.substr(0,s.find(delimiter));
            s.erase(0, pos + delimiter.length());
            //data inizio
            pos = s.find(delimiter);
            data_inizio_ = s.substr(0,s.find(delimiter));
            s.erase(0, pos + delimiter.length());
            //data fine
            data_fine_=s;


          //Ora ho le infrmazioni, creo i widget.
            layout_top->addWidget(new QLabel("Azienda: "),indice_riga,1);
            layout_top->addWidget(new QLineEdit(QString::fromStdString(nome_azienda_)),indice_riga++,2,1,2);
            layout_top->addWidget(new QLabel("Posizione: "),indice_riga,1);
            layout_top->addWidget(new QLineEdit(QString::fromStdString(posizione_)),indice_riga++,2,1,2);
            layout_top->addWidget(new QLabel("Luogo: "),indice_riga,1);
            layout_top->addWidget(new QLineEdit(QString::fromStdString(luogo_)),indice_riga++,2,1,2);
            QTextEdit* descrizione__=new QTextEdit(QString::fromStdString(descrizione_));
            descrizione__->setMinimumHeight(150);
           // descrizione__->setMaxCo
            layout_top->addWidget(new QLabel("Descrizione: "),indice_riga,1);
            layout_top->addWidget(descrizione__,indice_riga++,2,1,2);
            layout_top->addWidget(new QLabel("Da: "),indice_riga,1);
            layout_top->addWidget(new QLineEdit(QString::fromStdString(data_inizio_)),indice_riga++,2,1,2);
            layout_top->addWidget(new QLabel("A: "),indice_riga,1);
            layout_top->addWidget(new QLineEdit(QString::fromStdString(data_inizio_)),indice_riga++,2,1,2);
            layout_top->addWidget(new QLabel("<hr>"),indice_riga++,1,1,3);
        }
    }

   aggiungi_controlli_esperienza_professionale(indice_riga);
}
void client_profilo::disabilita_controlli_inserimento(const bool & b){
    disabilita_controlli_competenze(b);
    disabilita_controlli_lingua(b);

}
void client_profilo::aggiungi_controlli_lingua(int &indice_riga){
    riga_inizio_inserimento_lingua=indice_riga;
    lbl_inserimento_lingua=new QLabel("inserisci un nuova lingua");
    lbl_inserimento_lingua->setStyleSheet("font-style: italic;");
    layout_top->addWidget(lbl_inserimento_lingua,indice_riga++,1,1,3);
    nuova_descrizione_lingua=new QLineEdit("");
    layout_top->addWidget(nuova_descrizione_lingua, indice_riga,1,3,1);

    nuovo_livello_comprensione=new QComboBox();
    nuovo_livello_parlato=new QComboBox();
    nuovo_livello_scritto=new QComboBox();


    nuovo_livello_comprensione->addItems(livelli);
    nuovo_livello_parlato->addItems(livelli);
    nuovo_livello_scritto->addItems(livelli);


    layout_top->addWidget(new QLabel("comprensione: "),indice_riga,2);
    layout_top->addWidget(nuovo_livello_comprensione, indice_riga++,3);
    layout_top->addWidget(new QLabel("parlato: "),indice_riga,2);
    layout_top->addWidget(nuovo_livello_parlato, indice_riga++,3);
    layout_top->addWidget(new QLabel("scritto: "),indice_riga,2);
    layout_top->addWidget(nuovo_livello_scritto, indice_riga++,3);
    btn_aggiungi_lingua=new QPushButton("Inserisci Lingua");
    layout_top->addWidget(btn_aggiungi_lingua,indice_riga++,1,1,3);
    layout_top->addWidget(new QLabel("<hr>"),indice_riga++,1,1,3);

}
void client_profilo::aggiungi_controlli_esperienza_professionale(int &riga_corrente){

    lbl_esp_nuova_azienda = new QLabel("Azienda: ");
    lbl_esp_nuova_posizione = new QLabel("Posizione: ");
    lbl_esp_nuovo_luogo = new QLabel("Luogo: ");
    lbl_esp_nuova_descrizione = new QLabel("Decrizione: ");
    lbl_esp_nuova_data_inizio = new QLabel("Da: ");
    lbl_esp_nuova_data_fine = new QLabel("A: ");


    //Titolo
    QLabel* titolo =new QLabel("Aggiunta Esperienze\nProfessionali: ");
    layout_top->addWidget(titolo,riga_corrente++,1,1,3);
    //Azienda
    layout_top->addWidget(lbl_esp_nuova_azienda,riga_corrente,1);
    input_nuova_azienda = new QLineEdit;
    input_nuova_azienda->setPlaceholderText("Nome azienda");
    layout_top->addWidget(input_nuova_azienda,riga_corrente++,2,1,2);
    //Posizione
    layout_top->addWidget(lbl_esp_nuova_posizione,riga_corrente,1);
    input_nuova_posizione = new QLineEdit;
    input_nuova_posizione->setPlaceholderText("Ruolo ricoperto");
    layout_top->addWidget(input_nuova_posizione,riga_corrente++,2,1,2);
    //Luogo
    layout_top->addWidget(lbl_esp_nuovo_luogo,riga_corrente,1);
    input_nuovo_luogo = new QLineEdit;
    input_nuovo_luogo->setPlaceholderText("Indirizzo o Città");
    layout_top->addWidget(input_nuovo_luogo,riga_corrente++,2,1,2);
    //Descrizione
    layout_top->addWidget(lbl_esp_nuova_descrizione,riga_corrente,1);
    input_nuova_descrizione=new QTextEdit;
    input_nuova_descrizione->setMinimumHeight(300);
    input_nuova_descrizione->setPlaceholderText("Parla qui di quello che hai fatto ed imparato nell'esperienza!");
    layout_top->addWidget(input_nuova_descrizione,riga_corrente++,2,1,2);

    //Data inizio
    layout_top->addWidget(lbl_esp_nuova_data_inizio,riga_corrente++,1);
    cal_data_inizio= new QCalendarWidget;
    layout_top->addWidget(cal_data_inizio,riga_corrente++,1,1,3);
    //Data fine
    layout_top->addWidget(lbl_esp_nuova_data_fine,riga_corrente++,1);
    cal_data_fine= new QCalendarWidget;
    layout_top->addWidget(cal_data_fine,riga_corrente++,1,1,3);
    //bottone inserimento
    btn_inserisci_esperienza=new QPushButton("Inserisci esperienza");
    layout_top->addWidget(btn_inserisci_esperienza,riga_corrente,1,1,3);
}
void client_profilo::disabilita_controlli_esperienze_professionali(const bool &b){

}
void client_profilo::disabilita_controlli_lingua(const bool & b){
    if(b){
        layout_top->itemAtPosition(riga_inizio_inserimento_lingua,1)->widget()->hide();
        layout_top->itemAtPosition(riga_inizio_inserimento_lingua+2,1)->widget()->hide();

        for(int i=1;i<=3;i++){
            for(int j=2;j<=3;j++){
                layout_top->itemAtPosition(riga_inizio_inserimento_lingua+i,j)->widget()->hide();
                layout_top->itemAtPosition(riga_inizio_inserimento_lingua+i,j)->widget()->hide();
            }
        }
        layout_top->itemAtPosition(riga_inizio_inserimento_lingua+4,1)->widget()->hide();
        layout_top->itemAtPosition(riga_inizio_inserimento_lingua+5,1)->widget()->hide();
    }else{
        layout_top->itemAtPosition(riga_inizio_inserimento_lingua,1)->widget()->show();
        layout_top->itemAtPosition(riga_inizio_inserimento_lingua+2,1)->widget()->show();

        for(int i=1;i<=3;i++){
            for(int j=2;j<=3;j++){
                layout_top->itemAtPosition(riga_inizio_inserimento_lingua+i,j)->widget()->show();
                layout_top->itemAtPosition(riga_inizio_inserimento_lingua+i,j)->widget()->show();
            }
        }
        layout_top->itemAtPosition(riga_inizio_inserimento_lingua+4,1)->widget()->show();
        layout_top->itemAtPosition(riga_inizio_inserimento_lingua+5,1)->widget()->show();
    }
}
void client_profilo::disabilita_controlli_competenze(const bool &b){
    if(b){
        layout_top->removeWidget(btn_aggiungi_competenza);
        layout_top->removeWidget(nuova_competenza);
        if(lbl_hint_inserimento){
            layout_top->removeWidget(lbl_hint_inserimento);
        }
        btn_aggiungi_competenza->hide();
        nuova_competenza->hide();
        lbl_hint_inserimento->hide();
    }else{
        btn_aggiungi_competenza->show();
        nuova_competenza->show();
        layout_top->addWidget(btn_aggiungi_competenza,riga_fine_competenze+1,3);
        layout_top->addWidget(nuova_competenza,riga_fine_competenze+1,1,1,2);
    }
}
