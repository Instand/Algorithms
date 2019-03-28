if (MSVC) {
    QMAKE_CXXFLAGS += -std=c++17 /std:c++17
} else {
    CONFIG += c++17
}

CONFIG += console

HEADERS += ./algorithms.hpp \
    ./helper/algorithmstests.hpp \
    ./structures/linkedlist.hpp \
    ./helper/linkedlisttests.hpp \
    ./tests.hpp \
    ./utils.hpp \
    ./helper/taskstests.hpp \
    ./structures/forwardlist.hpp \
    framework.hpp \
    sort/stupidsort.hpp \
    sort/bublesort.hpp \
    sort/quicksort.hpp \
    sort/mergesort.hpp

SOURCES += ./main.cpp
