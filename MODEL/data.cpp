#include "data.h"

data::data(int g, int m, int a):giorno(g),mese(m),anno(a){
    if(sanitize(*this)==false){
        *this=data();
    }
}
bool data::sanitize(const int& g, const int& m, const int& a){ //STATICO
    return sanitize(data(g,m,a));
}
bool data::sanitize(const data& d) {                           //STATICO
    bool tutto_bene=false;

    if(d.mese>12 || d.mese<1 || d.giorno<1 || d.giorno >31) // sbarramento, ora devo controllare solo
        return false;                                       // i giorni del mese

    //FEBBRAIO
    if(d.mese==2 ){
        if( d.anno % 400 == 0 || (d.anno % 100 != 0 && d.anno % 4 == 0)){ //anno bisestile
            if(d.giorno<=29)
                tutto_bene=true;
        }else {
            if(d.giorno<=28)
                tutto_bene=true;
        }
    }else{
        //30 giorni: 4,6,9,11
        if(d.mese==4 || d.mese==6 || d.mese==9 || d.mese==11){
            if(d.giorno <=30)
                tutto_bene=true;
        }
        else tutto_bene=true;   //31 giorni: i rimantenti -> regolati da sbarramento.
    }
    return tutto_bene;
}

data data::converti_da_string(std::string s){    //draft!!!
    std::string giorno_, mese_,anno_;

    std::string delimiter = "-";
    size_t pos = 0;

    pos = s.find(delimiter);
    giorno_ = s.substr(0,s.find(delimiter));
    s.erase(0, pos + delimiter.length());
    pos = s.find(delimiter);
    mese_ = s.substr(0,s.find(delimiter));
    s.erase(0, pos + delimiter.length());
    anno_=s;

    int g,m,a;
    std::istringstream ( giorno_ ) >> g;
    std::istringstream ( mese_ ) >> m;
    std::istringstream ( anno_ ) >> a;
   // std::cout<<"giorno_"<<g<<",mese_"<<m<<",anno_"<<a<<std::endl;

    return data(g,m,a);
}

int data::get_giorno() const{
    return giorno;
}
int data::get_mese() const{
    return mese;
}
int data::get_anno() const{
    return anno;
}
bool data::aggiorna(const data& d){
    if (sanitize(d)){
        anno=d.anno;
        mese=d.mese;
        giorno=d.giorno;
        return true;
    }
    return false;
}
bool data::operator==(const data &d) const{
    return (giorno==d.get_giorno() && mese==d.get_mese() && anno==d.get_anno());
}

bool data::operator!=(const data &d) const {
    return !(*this==d);
}

bool data::operator<(const data &d)const{
    if(anno > d.anno)
        return false;
    if(anno < d.anno) {
        return true;
    }else {  //anno ==d.anno
        if(mese <= d.mese){
            if(giorno < d.giorno)
                return true;
        }
        return false;
    }
}

bool data::operator<=(const data & d) const{
    return ((*this==d) || (*this<d));
}

bool data::operator>(const data & d) const{
    return (!(*this<=d));
}

bool data::operator>=(const data & d) const{
    return (!(*this<d));
}

std::string data::toString() const{
    std::stringstream s;
    s << giorno << "-"<< mese << "-"<< anno;
    return s.str();

}
























