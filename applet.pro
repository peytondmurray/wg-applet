QT       += widgets
requires(qtConfig(combobox))

CONFIG += c++17
SOURCES += \
    main.cpp \
    window.cpp

HEADERS += \
    window.h

target.path = /tmp/$${TARGET}/bin
INSTALLS += target
