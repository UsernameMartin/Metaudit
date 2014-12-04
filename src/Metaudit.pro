#-------------------------------------------------
#
# Project created by QtCreator 2014-11-15T19:33:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Metaudit
TEMPLATE = app


SOURCES += main.cpp\
        fileselection.cpp \
    dataextractor.cpp \
    dataeditors.cpp \
    datasaver.cpp \
    genreselection.cpp \
    inputline.cpp \
    pictureselection.cpp

HEADERS  += fileselection.h \
    dataextractor.h \
    dataeditors.h \
    datasaver.h \
    genreselection.h \
    inputline.h \
    pictureselection.h

RESOURCES += qdarkstyle/style.qrc \

OTHER_FILES += \
    icon.ico

RC_FILE = metaudit.rc

win32:CONFIG(release, debug|release): LIBS += -L"C:\Libraries\taglib\lib" -ltag
else:win32:CONFIG(debug, debug|release): LIBS += -L"C:\Libraries\taglib\lib" -ltag
else:unix: LIBS += -ltag

win32:INCLUDEPATH += C:/Libraries/taglib/include/taglib
win32:DEPENDPATH += C:/Libraries/taglib/include/taglib
unix:INCLUDEPATH += /usr/include/taglib
unix:DEPENDPATH += /usr/include/taglib

CONFIG += static
