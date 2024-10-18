QT -= gui
QT += core
QT += network
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    database.cpp \
    functionsforserver.cpp \
    main.cpp \
    tcpserver.cpp

HEADERS += \
    database.h \
    functionsforserver.h \
    tcpserver.h

FORMS += \
    tcpserver.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
