QT       += core gui sql printsupport
QT       +=  sql
QT       += core gui multimedia multimediawidgets

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
    adherant.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    membre.cpp

HEADERS += \
    adherant.h \
    connection.h \
    mainwindow.h \
    membre.h

FORMS += \
    mainwindow.ui
QMAKE_CXXFLAGS += -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc

DISTFILES += \
    ../img ayed/add (1).png \
    ../img ayed/add.png \
    ../img ayed/age.png \
    ../img ayed/archive.png \
    ../img ayed/back (1).png \
    ../img ayed/back.png \
    ../img ayed/calendar.png \
    ../img ayed/camera.png \
    ../img ayed/cardiogram.png \
    ../img ayed/clear.png \
    ../img ayed/clock.png \
    ../img ayed/delivery (1).png \
    ../img ayed/delivery-man.png \
    ../img ayed/delivery.png \
    ../img ayed/email.png \
    ../img ayed/flask.png \
    ../img ayed/foldable-phone.png \
    ../img ayed/image (1).png \
    ../img ayed/image.png \
    ../img ayed/loop.png \
    ../img ayed/medical-equipment (1).png \
    ../img ayed/medical-equipment.png \
    ../img ayed/notes.png \
    ../img ayed/packages.png \
    ../img ayed/pdf.png \
    ../img ayed/phone-call.png \
    ../img ayed/printer.png \
    ../img ayed/real-estate.png \
    ../img ayed/report (1).png \
    ../img ayed/report.png \
    ../img ayed/search.png \
    ../img ayed/sort.png \
    ../img ayed/statistics.png \
    ../img ayed/web-search-engine.png \
    Obit.qss \
    pngegg (2).png
