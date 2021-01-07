QT       += core gui sql printsupport
QT       += core gui network
CONFIG   += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++11
QT += serialport
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    arduinodetec.cpp \
    client.cpp \
    commande.cpp \
    commandes.cpp \
    compte.cpp \
    connection.cpp \
    departement.cpp \
    detectiongaz.cpp \
    employer.cpp \
    fournisseurs.cpp \
    gestion_commande.cpp \
    gestion_emp.cpp \
    gestion_fournisseur.cpp \
    gestion_machine.cpp \
    gestion_stock.cpp \
    interventions.cpp \
    machines.cpp \
    main.cpp \
    mainwindow.cpp \
    produit.cpp \
    qcustomplot.cpp \
    stmp.cpp \
    stock.cpp

HEADERS += \
    arduino.h \
    arduinodetec.h \
    client.h \
    commande.h \
    commandes.h \
    compte.h \
    connection.h \
    departement.h \
    detectiongaz.h \
    employer.h \
    fournisseurs.h \
    gestion_commande.h \
    gestion_emp.h \
    gestion_fournisseur.h \
    gestion_machine.h \
    gestion_stock.h \
    interventions.h \
    machines.h \
    mainwindow.h \
    produit.h \
    qcustomplot.h \
    stmp.h \
    stock.h

FORMS += \
    detectiongaz.ui \
    gestion_commande.ui \
    gestion_emp.ui \
    gestion_fournisseur.ui \
    gestion_machine.ui \
    gestion_stock.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sons.qrc \
    sound.qrc \
    test_son.qrc
