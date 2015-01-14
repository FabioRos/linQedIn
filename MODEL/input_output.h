#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <QJsonObject>
#include "./MODEL/smart_utente.h"


class input_output{
private:
    static std::string file_path;    // va nel db
public:
    input_output();
    std::string get_file_path() const;
    bool carica_da_file();
    bool salva_su_file();
    void scrivi_un_utente(smart_utente*,QJsonObject& json_obj);

};

#endif // INPUT_OUTPUT_H
