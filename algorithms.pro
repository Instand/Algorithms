if (MSVC) {
    QMAKE_CXXFLAGS += -std=c++17 /std:c++17
} else {
    CONFIG += c++17
}

CONFIG += console

HEADERS += ./algorithms.hpp \
    ./helper/algorithmstests.hpp \
    ./linkedlist.hpp \
    ./helper/linkedlisttests.hpp \
    ./tests.hpp \
    ./utils.hpp \
    ./helper/taskstests.hpp \
    $$PWD/forwardlist.hpp \
    framework.hpp

SOURCES += ./main.cpp
