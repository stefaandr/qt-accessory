#-------------------------------------------------
#
# Project created by QtCreator 2014-07-24T22:16:46
#
#-------------------------------------------------

QT       += core

QMAKE_CXXFLAGS += -std=c++0x

TARGET = example
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Test.cpp \
    QtP.cpp \
    QtPBinding.cpp \
    QtPCombination.cpp \
    QtPConstant.cpp \
    QtPType.cpp \
    QtPObject.cpp \
    QtPAccess.cpp \
    QtPBase.cpp \
    QtPTraits.cpp

HEADERS += \
    Test.h \
    QtP.h \
    QtPBinding.h \
    QtPCombination.h \
    QtPConstant.h \
    QtPImpl.h \
    QtPType.h \
    QtPObject.h \
    QtPAccess.h \
    fwd.h \
    QtPBase.h \
    QtPTraits.h
