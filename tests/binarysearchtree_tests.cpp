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
