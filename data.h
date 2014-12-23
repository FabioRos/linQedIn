#ifndef DATA_H
#define DATA_H

class data{
private:
    int giorno;
    int mese;
    int anno;

    static bool sanitize(const int&, const int&, const int&);
public:
    static bool sanitize(const data&);
    explicit data(int =1, int =1, int =1970);
    int get_giorno() const;
    int get_mese() const;
    int get_anno() const;
    /*
     * non ho messo setter perche preferisco che l'aggiornamento sia
     * fatto con un'altra data per avere maggior controllo d'integrità.
     * Tanto basta pasarla per valore.
    */
    bool aggiorna(const data&);
    bool operator==(const data&);
};

#endif // DATA_H
