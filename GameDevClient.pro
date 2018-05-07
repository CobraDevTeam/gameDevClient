TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include(sfml.pri)

SOURCES += \
    main.cpp \
    sources/gui/component.cpp \
    sources/gui/container.cpp \
    sources/gui/label.cpp \
    sources/gui/button.cpp \
    sources/utility.cpp

HEADERS += \
    headers/resourcemanagement/resourceholder.hpp \
    headers/resourcemanagement/resourceholder.inl \
    headers/gui/component.hpp \
    headers/gui/container.hpp \
    headers/gui/label.hpp \
    headers/gui/button.hpp \
    headers/resourcemanagement/resourceidentifiers.hpp \
    headers/utility.hpp
