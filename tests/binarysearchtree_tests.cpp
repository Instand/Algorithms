#define TESTING

#include <gtest/gtest.h>

#include <utils.hpp>

#include <structures/binarysearchtree.hpp>

TEST(BinarySearchTree, TestInsert) {
    cs::BinarySearchTree<std::string, int> tree;

    tree.insert("Foo", 10);
    tree.insert("Bar", 20);
    tree.insert("Bar", 30);

    tree.visit([](const std::string& key, int value) {
        cs::Console::writeLine("Key ", key);
        cs::Console::writeLine("Value ", value);
    });

    ASSERT_EQ(tree.size(), 2);
}

TEST(BinarySearchTree, TestNonRecursiveVisit) {
    cs::BinarySearchTree<size_t, size_t> tree;

    tree.insert(20, 20);
    tree.insert(10, 10);
    tree.insert(30, 30);
    tree.insert(5, 5);
    tree.insert(15, 15);
    tree.insert(25, 25);
    tree.insert(35, 35);

    ASSERT_EQ(tree.size(), 7);

    size_t visitCount = 0;

    tree.nonRecursiveVisit([&](size_t key, size_t value) {
        cs::Console::writeLine("Key ", key);
        cs::Console::writeLine("Value ", value);

        visitCount++;
    });

    ASSERT_EQ(visitCount, tree.size());
}

TEST(BinarySearchTree, TestHeight) {
    cs::BinarySearchTree<int, int> tree;

    tree.insert(10, 10);
    tree.insert(5, 5);
    tree.insert(15, 15);
    tree.insert(1, 1);
    tree.insert(20, 20);

    ASSERT_EQ(2, tree.height());
}
