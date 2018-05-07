TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include(sfml.pri)

SOURCES += \
    main.cpp \
    sources/application.cpp \
    sources/connection/gateway.cpp \
    sources/connection/packet.cpp

HEADERS += \
    headers/resourcemanagemebnt/resourceholder.hpp \
    headers/resourcemanagement/resourceholder.inl \
    headers/application.hpp \
    headers/connection/gateway.hpp \
    headers/connection/packet.hpp \
    headers/resourcemanagement/resourceholder.hpp
