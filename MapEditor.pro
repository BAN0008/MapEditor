######################################################################
# Automatically generated by qmake (3.1) Thu Mar 29 16:42:15 2018
######################################################################

TEMPLATE = app
TARGET = MapEditor
INCLUDEPATH += .
QMAKE_LIBS += -lQt5Widgets
# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
SOURCES += src/Main.cpp src/MainWindow.cpp src/MainEditor.cpp
HEADERS += src/MainWindow.h src/MainEditor.h
