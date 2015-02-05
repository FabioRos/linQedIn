#include "smart_utente.h"

smart_utente::smart_utente(): ptr_utente(0){}

smart_utente::smart_utente(utente* ptr_u): ptr_utente(ptr_u){}

smart_utente::smart_utente(const smart_utente & su):ptr_utente(su.ptr_utente->clona_utente()){}
                    //c'è bisogno di un metodo polimorfo di clonazione su utente.

smart_utente::~smart_utente(){delete ptr_utente;}

smart_utente &smart_utente::operator=(const smart_utente &u)
{   if(this!=&u){
        delete ptr_utente;
        ptr_utente=u.ptr_utente;
    }
    return *this;
}

void smart_utente::set_ptr_utente(utente *u){
     if(ptr_utente!=u){
        delete ptr_utente;
         ptr_utente=u;
     }
}

utente *smart_utente::get_ptr_utente() const{
    return ptr_utente;
}

bool smart_utente::cambio_tipo_utente(const std::string & nuovo_tipo,const std::string & cc ){
    //cambiare con uno switch e controllare this !=0
    bool tutto_bene=false;
    if(ptr_utente!=0){

        int valore;
        if(nuovo_tipo=="basic") valore=1;
        if(nuovo_tipo=="business") valore=50;
        if(nuovo_tipo=="executive") valore=51;

        switch(valore){
            case 1:{    //basic
                utente* temp=this->ptr_utente;
                utente_basic* ptr_nuovo_utente=new utente_basic(*temp);
                delete temp;
                ptr_utente=ptr_nuovo_utente;
                tutto_bene=true;
            };break;

            case 50:{   //business
                utente* temp=this->ptr_utente;
                utente_business* ptr_nuovo_utente=new utente_business(*temp);
                if(dynamic_cast<utente_gratis*>(ptr_utente))  {  //allora è gratis
                    //manca la carta di credito
                    ptr_nuovo_utente->set_carta_di_credito(cc);
                }
                delete temp;
                ptr_utente=ptr_nuovo_utente;
                tutto_bene=true;
            };break;

            case 51:{   //executive
                utente* temp=this->ptr_utente;
                utente_executive* ptr_nuovo_utente=new utente_executive(*temp);
                if(dynamic_cast<utente_gratis*>(ptr_utente))  {  //allora è gratis
                    //manca la carta di credito
                    ptr_nuovo_utente->set_carta_di_credito(cc);
                }
                delete temp;
                ptr_utente=ptr_nuovo_utente;
                tutto_bene=true;
            };break;

            default:{
                //eccezione
            };break;
        }
    }
    return tutto_bene;
}




