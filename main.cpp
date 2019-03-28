#include <iostream>
#include <tests.hpp>

int main() {
    cs::testLinkedList();
    cs::testSorts();
    cs::testAlgorithms();
    cs::testTasks();

    cs::Console::writeLine("All test cases OK");
    return 0;
}
