QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../../kmeanslib/kmeanslib.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-kmeanslib-Desktop_Qt_6_4_2_MinGW_64_bit-Release/release/ -lkmeanslib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-kmeanslib-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/debug/ -lkmeanslib
else:unix: LIBS += -L$$PWD/../../build-kmeanslib-Desktop_Qt_6_4_2_MinGW_64_bit-Release/ -lkmeanslib

INCLUDEPATH += $$PWD/../../build-kmeanslib-Desktop_Qt_6_4_2_MinGW_64_bit-Release/release
DEPENDPATH += $$PWD/../../build-kmeanslib-Desktop_Qt_6_4_2_MinGW_64_bit-Release/release
