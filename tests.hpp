#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>

#include <helper/linkedlisttests.hpp>
#include <helper/algorithmstests.hpp>
#include <helper/taskstests.hpp>

#include <framework.hpp>

namespace cs {
    void testLinkedList() {
        Framework::execute(&cs::LinkedListTests::testPushBack, "Linked list push back test failed");
        Framework::execute(&cs::LinkedListTests::testPushFront, "Linked list push front test failed");
        Framework::execute(&cs::LinkedListTests::testInsert, "Linked list insert at the head failed");
        Framework::execute(&cs::LinkedListTests::testFindAndRemove, "Linked list find and remove failed");
        Framework::execute(&cs::LinkedListTests::testReverse, "Linked list reverse failed");
    }

    void testAlgorithms() {
        Framework::execute(&cs::AlgorithmsTests::testBubleSort, "Buble sort failed");
        Framework::execute(&cs::AlgorithmsTests::testStupidSort, "Stupid sort failed");
        Framework::execute(&cs::AlgorithmsTests::testQuickSort, "Quick sort tests failed");
        Framework::execute(&cs::AlgorithmsTests::testHex, "Hex tests failed");
        Framework::execute(&cs::AlgorithmsTests::testPrime, "Primes tests failed");
        Framework::execute(&cs::AlgorithmsTests::testFactorial, "Factorial tests failed");
        Framework::execute(&cs::AlgorithmsTests::testSwap, "Swap tests failed");
    }

    void testTasks() {
        Framework::execute(&cs::TasksTests::removeEverySecondElement, "Remove every second element tests failed");
        Framework::execute(&cs::TasksTests::mergeTwoOrderedVectors, "Merge two ordered vectors failed");
    }
}

#endif // TESTS_HPP
