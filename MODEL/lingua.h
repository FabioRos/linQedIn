#ifndef LINGUA_H
#define LINGUA_H

#include <string>
#include <QJsonObject>

class lingua{
private:

    std::string descrizione;
    std::string livello_comprensione;
    std::string livello_parlato;
    std::string livello_scritto;

public:
    explicit lingua(const std::string&, const std::string&, const std::string&, const std::string&);
    static std::string livelli[6];
    std::string get_descrizione() const;
    std::string get_livello_comprensione() const;
    std::string get_livello_parlato() const;
    std::string get_livello_scritto() const;
    void set_descrizione(const std::string&);
    void set_livello_comprensione(const std::string&);
    void set_livello_parlato(const std::string&);
    void set_livello_scritto(const std::string&);
    static bool sanitize(const lingua&);

    virtual void scrivi_json(QJsonObject &json) const;

};

#endif // LINGUA_H
