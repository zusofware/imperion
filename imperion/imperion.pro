QT       += core gui widgets sql websockets printsupport concurrent network

CONFIG(USE_EMBED_BROWSER) {
    DEFINES+=USE_EMBED_BROWSER
    CONFIG(USE_WEBENGINE) {
        QT += webenginewidgets
        DEFINES += USE_WEBENGINE
    } else {
        QT += webkitwidgets
    }
}

TARGET = Imperion
TEMPLATE = app

CONFIG += c++11

contains(CONFIG, SINGLEBIN) {
    include(../external_library/o2/src/src.pri)
    include(../libglobal/libglobal_src.pri)
    include(../libprint/libprint_src.pri)
    include(../libdb/libdb_src.pri)
    include(../libserver/libserver_src.pri)
    include(../libgui/libgui_src.pri)
} else {
    include(../libglobal/libglobal.pri)
    include(../libprint/libprint.pri)
    include(../libdb/libdb.pri)
    include(../libserver/libserver.pri)
    include(../libgui/libgui.pri)
}

CONFIG(NO_PRINTER_DEVICE) {
    DEFINES+=NO_PRINTER_DEVICE
}

macx {
    QMAKE_LIBDIR += $$OUT_PWD/../bin/Imperion.app/Contents/Frameworks
    LIBS += -framework Foundation
    contains(CONFIG, SINGLEBIN) {
        DEFINES+=SINGLEBIN
        LIBS += -lcups
    }
    DESTDIR = ../bin
} else:win32 {
    LIBS += -L$$OUT_PWD/../bin
    contains(CONFIG, SINGLEBIN) {
        DEFINES+=SINGLEBIN
        !contains(CONFIG, NO_PRINTER_SPOOL) {
            LIBS += -lKernel32 -lwinspool
        } else {
            DEFINES+=NO_PRINTER_SPOOL
        }
    }
    RC_FILE = imperion.rc
    DESTDIR = ../bin/
    PWD_WIN = $${PWD}
    DESTDIR_WIN = $$OUT_PWD/../bin/
    PWD_WIN ~= s,/,\\,g
    DESTDIR_WIN ~= s,/,\\,g
} else {
    QMAKE_LIBDIR = $$OUT_PWD/../bin $$QMAKE_LIBDIR
    LIBS += -L$$OUT_PWD/../bin
    contains(CONFIG, SINGLEBIN) {
        DEFINES+=SINGLEBIN
        !contains(CONFIG, NO_PRINTER_SPOOL) {
            LIBS += -lcups
        } else {
            DEFINES+=NO_PRINTER_SPOOL
        }
    }
    contains(CONFIG, USE_LIBUSB) {
        DEFINES+=USE_LIBUSB
        LIBS += -lusb-1.0 -ludev
    }
    DESTDIR = ../bin
    copysh.commands = $$quote(cp -R $${PWD}/../script/Imperion.sh $${OUT_PWD}/../bin/)
    QMAKE_EXTRA_TARGETS += copysh
    POST_TARGETDEPS += copysh
}

RESOURCES += imperion.qrc sqlmigration.qrc translation.qrc

TRANSLATIONS = ../translation/imperion_id.ts

SOURCES += main.cpp \
    core.cpp \
    socket/socketmanager.cpp \
    socket/socketclient.cpp \
    socket/sockethandler.cpp

HEADERS  += \
    core.h \
    socket/socketmanager.h \
    socket/socketclient.h \
    socket/sockethandler.h

FORMS +=
