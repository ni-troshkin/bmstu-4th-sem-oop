QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cleaner.cpp \
    linkio.cpp \
    main.cpp \
    interface.cpp \
    model_cdio.cpp \
    movescale.cpp \
    pointio.cpp \
    processing.cpp \
    reader.cpp \
    rotation.cpp \
    transform.cpp \
    writer.cpp

HEADERS += \
    args.h \
    cleaner.h \
    interface.h \
    linkio.h \
    model.h \
    model_cdio.h \
    movescale.h \
    pointio.h \
    processing.h \
    reader.h \
    rotation.h \
    transform.h \
    writer.h

FORMS += \
    interface.ui

TRANSLATIONS += \
    lab_01_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-lab_01-Desktop-Debug/hex_pyramid.txt \
    ../build-lab_01-Desktop-Debug/prism.txt \
    ../build-lab_01-Desktop-Debug/pyramid.txt \
    cube.txt
