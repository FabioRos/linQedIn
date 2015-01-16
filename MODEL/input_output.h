#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <QJsonObject>
#include <QJsonArray>
#include "db.h"
#include "./MODEL/smart_utente.h"

#define file_path "/home/fabio/Development/C++/PaO_2014_15/LinQedIn/LinQedIn/PERSISTENT/database.json"

class input_output{
private:
    //static std::string file_path;    // va nel db
public:
    input_output();
    std::string get_file_path() const;
    bool carica_da_file();
    bool salva_su_file(DB*);
    void scrivi_un_utente(smart_utente*,QJsonObject& json_obj);
    QJsonArray serializza_db(const std::list<smart_utente*>&) const;

};

#endif // INPUT_OUTPUT_H
