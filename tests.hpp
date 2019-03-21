#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>

#include <helper/linkedlisttests.hpp>
#include <helper/algorithmstests.hpp>
#include <helper/taskstests.hpp>

namespace cs {
    void testLinkedList() {
        if (!cs::Benchmark::run(&cs::LinkedListTests::testPushBack)) {
            cs::Console::writeLine("Linked list push bakc test failed");
        }

        if (!cs::Benchmark::run(&cs::LinkedListTests::testPushFront)) {
            cs::Console::writeLine("Linked list push front test failed");
        }

        if (!cs::Benchmark::run(&cs::LinkedListTests::testInsert)) {
            cs::Console::writeLine("Linked list insert at the head failed");
        }

        if (!cs::Benchmark::run(&cs::LinkedListTests::testFindAndRemove)) {
            cs::Console::writeLine("Linked list find and remove failed");
        }

        if (!cs::Benchmark::run(&cs::LinkedListTests::testReverse)) {
            cs::Console::writeLine("Linked list reverse failed");
        }
    }

    void testAlgorithms() {
        if (!cs::Benchmark::run(&cs::AlgorithmsTests::testBubleSort)) {
            cs::Console::writeLine("Buble sort failed");
        }

        if (!cs::Benchmark::run(&cs::AlgorithmsTests::testStupidSort)) {
            cs::Console::writeLine("Stupid sort failed");
        }

        if (!cs::Benchmark::run(&cs::AlgorithmsTests::testQuickSort)) {
            cs::Console::writeLine("Quick sort tests failed");
        }

        if (!cs::Benchmark::run(&cs::AlgorithmsTests::testHex)) {
            cs::Console::writeLine("Hex tests failed");
        }

        if (!cs::Benchmark::run(&cs::AlgorithmsTests::testPrime)) {
            cs::Console::writeLine("Primes tests failed");
        }

        if (!cs::Benchmark::run(&cs::AlgorithmsTests::testFactorial)) {
            cs::Console::writeLine("Factorial tests failed");
        }
    }

    void testTasks() {
        if (!cs::Benchmark::run(&cs::TasksTests::removeEverySecondElement)) {
            cs::Console::writeLine("Remove every second element tests failed");
        }

        if (!cs::Benchmark::run(&cs::TasksTests::mergeTwoOrderedVectors)) {
            cs::Console::writeLine("Merge two ordered vectors failed");
        }
    }
}

#endif // TESTS_HPP
