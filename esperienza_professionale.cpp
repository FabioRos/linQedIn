#include "esperienza_professionale.h"

esperienza_professionale::esperienza_professionale(const std::string & a, const std::string & p,
                                                   const std::string & l, const std::string & d,
                                                   const data & i, const data & f)
    :nome_azienda(a), posizione(p),attivita(l,d,i,f){}

std::string esperienza_professionale::get_nome_azienda() const{
    return nome_azienda;
}
std::string esperienza_professionale::get_posizione() const{
    return posizione;
}
void esperienza_professionale::aggiorna_nome_azienda(const std::string& s){
    nome_azienda=s;
}
void esperienza_professionale::aggiorna_posizione(const std::string& s){
    posizione=s;
}

bool esperienza_professionale::operator==(const esperienza_professionale & e){
    return ( e.get_descrizione()==get_descrizione() &&
             e.get_fine()==get_fine() &&
             e.get_inizio()==get_inizio()&&
             e.get_luogo()==get_luogo() &&
             e.nome_azienda==nome_azienda &&
             e.posizione == posizione);
}
bool esperienza_professionale::operator!=(const esperienza_professionale & e){
    return !(*this==e);
}


//bool esperienza_professionale::operator==(const esperienza_professionale &e){
//    return (luogo==e.get_luogo()&& descrizione==e.get_descrizione() && inizio==e.get_inizio() &&
//            fine== e.get_fine() && nome_azienda==e.get_nome_azienda() && posizione==e.get_posizione());
//}
