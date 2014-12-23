#include "titolo_di_studio.h"

titolo_di_studio::titolo_di_studio(const std::string& ente, const std::string& l,
                                   const std::string& d, const data& i , const data& f)
    :ente_erogante(ente),attivita(l,d,i,f){}

std::string titolo_di_studio::get_ente_erogante() const{
    return ente_erogante;
}

void titolo_di_studio::aggiorna_ente_erogante(const std::string& s){
    ente_erogante=s;

}
