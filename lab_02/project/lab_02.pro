TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        base_container.cpp \
        base_exception.cpp \
        main.cpp

HEADERS += \
    base_container.h \
    base_exception.h \
    constiter.h \
    constiter.hpp \
    exceptions.h \
    iterator.h \
    iterator.hpp \
    vector.h \
    vector.hpp \
    vector_копия.h
