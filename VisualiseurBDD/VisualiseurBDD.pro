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
    Login.cpp \
    MainWindow.cpp \
    ManageUser.cpp \
    Profile.cpp \
    ReadWriteJson.cpp \
    SelectProfile.cpp \
    User.cpp \
    main.cpp

HEADERS += \
    CreateProfile.h \
    CreateUser.h \
    Data.h \
    Login.h \
    MainWindow.h \
    ManageUser.h \
    Profile.h \
    ReadWriteJson.h \
    SelectProfile.h \
    User.h

FORMS += \
    CreateProfile.ui \
    CreateUser.ui \
    Login.ui \
    MainWindow.ui \
    ManageUser.ui \
    SelectProfile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
