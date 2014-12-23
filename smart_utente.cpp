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




