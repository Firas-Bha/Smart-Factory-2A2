QT       += core gui sql printsupport
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
TARGET = test_son

TEMPLATE = app
SOURCES += \
    connection.cpp \
    equipements.cpp \
    interventions.cpp \
    machines.cpp \
    main.cpp \
    qcustomplot.cpp

HEADERS += \
    connection.h \
    equipements.h \
    interventions.h \
    machines.h \
    qcustomplot.h

FORMS += \
    equipements.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    test_son.qrc
