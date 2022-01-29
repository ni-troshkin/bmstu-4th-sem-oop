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
    basedirector.cpp \
    camera.cpp \
    camerabuilder.cpp \
    cameracommand.cpp \
    cameradirector.cpp \
    composite.cpp \
    drawmanager.cpp \
    drawmanagercreator.cpp \
    edge.cpp \
    exportmanager.cpp \
    exportmanagercreator.cpp \
    facade.cpp \
    facadecreator.cpp \
    filecameraexporter.cpp \
    filecameraloader.cpp \
    filemodelexporter.cpp \
    filemodelloader.cpp \
    filesceneexporter.cpp \
    filesceneloader.cpp \
    loadmanager.cpp \
    loadmanagercreator.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    modelbuilder.cpp \
    modelcommand.cpp \
    modeldirector.cpp \
    modelimplementation.cpp \
    object.cpp \
    point.cpp \
    qtdrawer.cpp \
    qtfactory.cpp \
    scene.cpp \
    scenebuilder.cpp \
    scenecommand.cpp \
    scenedirector.cpp \
    scenemanager.cpp \
    scenemanagercreator.cpp \
    transformmanager.cpp \
    transformmanagercreator.cpp \
    visitor.cpp

HEADERS += \
    abstractgraphicsfactory.h \
    basebuilder.h \
    basecameraexporter.h \
    basecameraloader.h \
    basecommand.h \
    basedirector.h \
    basedrawer.h \
    baseexporter.h \
    baseloader.h \
    basemanager.h \
    basemodelexporter.h \
    basemodelloader.h \
    basesceneexporter.h \
    basesceneloader.h \
    basevisitor.h \
    camera.h \
    camerabuilder.h \
    cameracommand.h \
    cameradirector.h \
    composite.h \
    drawmanager.h \
    drawmanagercreator.h \
    edge.h \
    exportmanager.h \
    exportmanagercreator.h \
    facade.h \
    facadecreator.h \
    filecameraexporter.h \
    filecameraloader.h \
    filemodelexporter.h \
    filemodelloader.h \
    filesceneexporter.h \
    filesceneloader.h \
    loadmanager.h \
    loadmanagercreator.h \
    mainwindow.h \
    model.h \
    modelbuilder.h \
    modelcommand.h \
    modeldirector.h \
    modelimplementation.h \
    object.h \
    point.h \
    qtdrawer.h \
    qtfactory.h \
    scene.h \
    scenebuilder.h \
    scenecommand.h \
    scenedirector.h \
    scenemanager.h \
    scenemanagercreator.h \
    transformmanager.h \
    transformmanagercreator.h \
    visitor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
