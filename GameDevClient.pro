TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include(sfml.pri)

SOURCES += \
    main.cpp \
    sources/application.cpp \
    sources/connection/gateway.cpp \
    sources/connection/packet.cpp \
    sources/gui/component.cpp \
    sources/gui/container.cpp \
    sources/gui/label.cpp \
    sources/gui/button.cpp \
    sources/utility.cpp \
    sources/states/statestack.cpp \
    sources/states/state.cpp \
    sources/states/connectionmenustate.cpp \
    sources/states/mainmenustate.cpp \
    sources/gui/textinput.cpp

HEADERS += \
    headers/resourcemanagemebnt/resourceholder.hpp \
    headers/resourcemanagement/resourceholder.inl \
    headers/resourcemanagement/resourceidentifiers.hpp \
    headers/application.hpp \
    headers/connection/gateway.hpp \
    headers/connection/packet.hpp \
    headers/gui/component.hpp \
    headers/gui/container.hpp \
    headers/gui/label.hpp \
    headers/gui/button.hpp \
    headers/utility.hpp \
    headers/states/statestack.hpp \
    headers/states/state.hpp \
    headers/states/stateidentifier.hpp \
    headers/states/mainmenustate.hpp \
    headers/states/connectionmenustate.hpp \
    headers/gui/textinput.hpp
