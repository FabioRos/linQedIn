#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>

class login : public QWidget{
private:
    Q_OBJECT

    QLineEdit* input_username;
    QHBoxLayout* layout_login;
    QPushButton* btn_login;
public:
    login(QWidget* parent =0);

public slots:
    void login_autorizzato();
};

#endif // LOGIN_H
