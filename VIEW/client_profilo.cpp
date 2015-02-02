#include "client_profilo.h"
#include <QLayoutItem>
#include <QComboBox>
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
    btn_aggiungi_competenza->show();
    nuova_competenza->show();
    layout_top->addWidget(btn_aggiungi_competenza,riga_fine_competenze+1,3);
    layout_top->addWidget(nuova_competenza,riga_fine_competenze+1,1,1,2);
}

void client_profilo::salva_modifiche(){
    disabilita_tutto();
    btn_modifica_profilo->show();
    btn_salva_modifiche->hide();
    //salva
    layout_top->removeWidget(btn_salva_modifiche);
    layout_top->addWidget(btn_modifica_profilo,1,3);

    //da portare fuori
    layout_top->removeWidget(btn_aggiungi_competenza);
    layout_top->removeWidget(nuova_competenza);
    if(lbl_hint_inserimento){
        layout_top->removeWidget(lbl_hint_inserimento);
    }
    btn_aggiungi_competenza->hide();
    nuova_competenza->hide();
    //layout_top->removeWidget(lbl_hint_inserimento);
    lbl_hint_inserimento->hide();
    //ptr_scroll_area_contenitore->adjustSize();
    //layout_top->


}

void client_profilo::aggiungi_competenza(){
    lbl_hint_inserimento->hide();
    if( numero_competenze<18){
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
    abilita_disabilita_competenze(true);
    abilita_disabilita_lingue(true);


}

void client_profilo::abilita_tutto(){
    nome->setDisabled(false);
    cognome->setDisabled(false);
    username->setDisabled(false);
    //competenze
    abilita_disabilita_competenze(false);
    abilita_disabilita_lingue(false);


    //layout_top->itemAtPosition(r,c)
}

void client_profilo::abilita_disabilita_competenze(const bool &value){
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


                // LOOP !!!



                //!!MODO PER PRENDERSI WIDGETS ANONIMI DAL LAYOUT!!
                //std::cout<<"("<<r<<","<<i%4<<")   ";
                if(layout_top->itemAtPosition(r,i%4))
                    layout_top->itemAtPosition(r,i%4)->widget()->setDisabled(value);

            }
        }
    }

}

void client_profilo::abilita_disabilita_lingue(const bool &value){//true disabilita
    int r_c=riga_fine_competenze+4;   //4 sono quelle di
    //lasco per inserire fino a 18 competenze
    //std::cout<<"\n\nnumero_lingue:  "<<numero_lingue<<"\n\n";
    if(numero_lingue){
        // std::cout<<numero_lingue;
        for(int i=1;i<=numero_lingue;i++){
            layout_top->itemAtPosition(r_c+(3*i),1)->widget()->setDisabled(value);
            //          layout_top->itemAtPosition(r_c+(3*i),3)->widget()->setDisabled(value);
            //          layout_top->itemAtPosition(r_c+(3*i)+1,3)->widget()->setDisabled(value);
            //          layout_top->itemAtPosition(r_c+(3*i)+2,3)->widget()->setDisabled(value);
            for(int j=0;j<3;j++){
                if(layout_top->itemAtPosition(r_c+(3*i)+j,3)){
                    layout_top->itemAtPosition(r_c+(3*i)+j,3)->widget()->setDisabled(value);
                }
            }
        }
    }//else std::cout<<"r_c+"<<i<<": " <<r_c+i<< "\n";



    ///per la riga r_c devo disabilitare i widgets in posizione (x,y):
    ///
    /*
            (r_c,1),(r_c,2),(r_c,3),(r_c+1,2),(r_c+1,3),(r_c+2,2),(r_c+2,3),
        */


    //std::cout<<"("<<r<<","<<i%4<<")   ";
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
    int indice_riga=5;
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

    //qui devo inserire dalla riga "indice_riga+2" //per bottone e lbl_hint
    indice_riga+=2;

    //LINGUE
    ++it;
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

            QStringList livelli;
            livelli << "A1" << "A2" << "B1" << "B2"<< "C1" << "C2";

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

            indice_riga+=3;
        }

    }
}
