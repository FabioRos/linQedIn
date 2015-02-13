######################################################################
# Automatically generated by qmake (2.01a) sab gen 3 12:13:27 2015
######################################################################

TEMPLATE = app
TARGET = LinQedIn
DEPENDPATH += . TEST VIEW
INCLUDEPATH += . VIEW TEST


QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Input
HEADERS += TEST/test.h \
           TEST/test_data.h \
           TEST/test_esperienza.h \
           TEST/test_lingua.h \
           TEST/test_manager.h \
           TEST/test_utente_basic.h \
    MODEL/attivita.h \
    MODEL/data.h \
    MODEL/db.h \
    MODEL/esperienza_professionale.h \
    MODEL/lingua.h \
    MODEL/rete.h \
    MODEL/smart_utente.h \
    MODEL/titolo_di_studio.h \
    MODEL/utente.h \
    MODEL/utente_a_pagamento.h \
    MODEL/utente_basic.h \
    MODEL/utente_business.h \
    MODEL/utente_executive.h \
    MODEL/utente_gratis.h \
    VIEW/finestraprincipale.h \
    VIEW/testing.h \
    TEST/test_rete.h \
    VIEW/login.h \
    CONTROLLER/client_controller.h \
    VIEW/menu_amministrazione.h \
    VIEW/client_manager.h \
    VIEW/tool_bar.h \
    VIEW/tab_wrapper.h \
    VIEW/aggiunta_utente.h \
    VIEW/modulo_lingua.h \
    VIEW/modulo_competenza.h \
    VIEW/modulo_esperienza_professionale.h \
    TEST/test_utente_business.h \
    TEST/test_db.h \
    VIEW/modulo_visualizzazione_utenti.h \
    CONTROLLER/admin_controller.h \
    TEST/test_smart_utente.h \
    MODEL/users_repository.h \
    CONTROLLER/aggiungi_modifica_utenti.h \
    MODEL/input_output.h \
    VIEW/amministrazione.h \
    VIEW/modulo_rimozione_utenti.h \
    VIEW/client_profilo.h \
    VIEW/client_environment.h \
    VIEW/cambia_tipo_utente.h \
    VIEW/cerca.h \
    VIEW/profilo_popup.h
SOURCES += main.cpp \
           TEST/test.cpp \
           TEST/test_data.cpp \
           TEST/test_esperienza.cpp \
           TEST/test_lingua.cpp \
           TEST/test_manager.cpp \
           TEST/test_utente_basic.cpp \
    MODEL/attivita.cpp \
    MODEL/data.cpp \
    MODEL/db.cpp \
    MODEL/esperienza_professionale.cpp \
    MODEL/lingua.cpp \
    MODEL/rete.cpp \
    MODEL/smart_utente.cpp \
    MODEL/titolo_di_studio.cpp \
    MODEL/utente.cpp \
    MODEL/utente_a_pagamento.cpp \
    MODEL/utente_basic.cpp \
    MODEL/utente_business.cpp \
    MODEL/utente_executive.cpp \
    MODEL/utente_gratis.cpp \
    VIEW/finestraprincipale.cpp \
    VIEW/testing.cpp \
    TEST/test_rete.cpp \
    VIEW/login.cpp \
    #moc_finestraprincipale.cpp \
    CONTROLLER/client_controller.cpp \
    VIEW/menu_amministrazione.cpp \
    VIEW/client_manager.cpp \
    VIEW/tool_bar.cpp \
    VIEW/tab_wrapper.cpp \
    VIEW/aggiunta_utente.cpp \
    VIEW/modulo_lingua.cpp \
    VIEW/modulo_competenza.cpp \
    VIEW/modulo_esperienza_professionale.cpp \
    TEST/test_utente_business.cpp \
    TEST/test_db.cpp \
    VIEW/modulo_visualizzazione_utenti.cpp \
    CONTROLLER/admin_controller.cpp \
    TEST/test_smart_utente.cpp \
    MODEL/users_repository.cpp \
    CONTROLLER/aggiungi_modifica_utenti.cpp \
    MODEL/input_output.cpp \
    VIEW/amministrazione.cpp \
    VIEW/modulo_rimozione_utenti.cpp \
    VIEW/client_profilo.cpp \
    VIEW/client_environment.cpp \
    VIEW/cambia_tipo_utente.cpp \
    VIEW/cerca.cpp \
    VIEW/profilo_popup.cpp

OTHER_FILES += \
    PERSISTENT/database.json



