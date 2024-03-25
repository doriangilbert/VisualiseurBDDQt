QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CreateProfile.cpp \
    CreateUser.cpp \
    Data.cpp \
    DatabasesList.cpp \
    Login.cpp \
    MainWindow.cpp \
    ManageDatabase.cpp \
    ManageUser.cpp \
    Profile.cpp \
    QueryMaker.cpp \
    QueryResult.cpp \
    ReadWriteJson.cpp \
    SelectProfile.cpp \
    TableView.cpp \
    User.cpp \
    lib/shell.c \
    lib/sqlite3.c \
    main.cpp

HEADERS += \
    CreateProfile.h \
    CreateUser.h \
    Data.h \
    DatabasesList.h \
    Login.h \
    MainWindow.h \
    ManageDatabase.h \
    ManageUser.h \
    Profile.h \
    QueryMaker.h \
    QueryResult.h \
    ReadWriteJson.h \
    SelectProfile.h \
    TableView.h \
    User.h \
    lib/sqlite3.h \
    lib/sqlite3ext.h

FORMS += \
    CreateProfile.ui \
    CreateUser.ui \
    DatabasesList.ui \
    Login.ui \
    MainWindow.ui \
    ManageDatabase.ui \
    ManageUser.ui \
    QueryMaker.ui \
    QueryResult.ui \
    SelectProfile.ui \
    TableView.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
