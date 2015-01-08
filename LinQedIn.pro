######################################################################
# Automatically generated by qmake (2.01a) sab gen 3 12:13:27 2015
######################################################################

TEMPLATE = app
TARGET = LinQedIn
DEPENDPATH += . TEST VIEW
INCLUDEPATH += . VIEW TEST


QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT+=widgets

# Input
HEADERS += TEST/test.h \
           TEST/test_data.h \
           TEST/test_esperienza.h \
           TEST/test_lingua.h \
           TEST/test_manager.h \
           TEST/test_utente_basic.h \
           VIEW/amministazione.h \
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
    VIEW/menu_bar.h \
    CONTROLLER/client_controller.h \
    VIEW/menu_amministrazione.h \
    VIEW/client_manager.h \
    VIEW/tool_bar.h \
    VIEW/tab_wrapper.h \
    VIEW/aggiunta_utente.h \
    VIEW/modulo_lingua.h
SOURCES += main.cpp \
           TEST/test.cpp \
           TEST/test_data.cpp \
           TEST/test_esperienza.cpp \
           TEST/test_lingua.cpp \
           TEST/test_manager.cpp \
           TEST/test_utente_basic.cpp \
           VIEW/amministazione.cpp \
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
    VIEW/menu_bar.cpp \
    #moc_finestraprincipale.cpp \
    CONTROLLER/client_controller.cpp \
    VIEW/menu_amministrazione.cpp \
    VIEW/client_manager.cpp \
    VIEW/tool_bar.cpp \
    VIEW/tab_wrapper.cpp \
    VIEW/aggiunta_utente.cpp \
    VIEW/modulo_lingua.cpp



