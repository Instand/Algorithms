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
    {
        cs::BinarySearchTree<int, int> tree;

        tree.insert(10, 10);
        tree.insert(5, 5);
        tree.insert(15, 15);
        tree.insert(1, 1);
        tree.insert(20, 20);

        ASSERT_EQ(2, tree.height());
    }

    {
        cs::BinarySearchTree<int, int> tree;

        tree.insertRoot(10, 10);
        cs::Console::writeLine("Root ", tree.root());
        ASSERT_EQ(10, tree.root());

        tree.insertRoot(5, 5);
        cs::Console::writeLine("Root ", tree.root());
        ASSERT_EQ(5, tree.root());

        tree.insertRoot(15, 15);
        cs::Console::writeLine("Root ", tree.root());
        ASSERT_EQ(15, tree.root());

        tree.insertRoot(1, 1);
        cs::Console::writeLine("Root ", tree.root());
        ASSERT_EQ(1, tree.root());

        tree.insertRoot(20, 20);
        cs::Console::writeLine("Root ", tree.root());
        ASSERT_EQ(20, tree.root());

        ASSERT_EQ(4, tree.height());
    }
}

TEST(BinarySearchTree, TestErase) {
    cs::BinarySearchTree<int, int> tree;

    tree.insert(10, 10);
    tree.insert(8, 8);
    tree.insert(5, 5);
    tree.insert(15, 15);
    tree.insert(20, 20);
    tree.insert(11, 11);

    ASSERT_EQ(10, tree.root());

    tree.erase(10);

    tree.visit([](int key, int value) {
       cs::Console::writeLine("Key: ", key);
       cs::Console::writeLine("Value: ", value);
    });

    ASSERT_EQ(11, tree.root());
}

TEST(BinarySearchTree, TestJoin) {
    cs::BinarySearchTree<int, int> tree1;

    tree1.insert(10, 10);
    tree1.insert(5, 5);
    tree1.insert(15, 15);

    cs::BinarySearchTree<int, int> tree2;

    tree2.insert(8, 8);
    tree2.insert(3, 3);
    tree2.insert(9, 9);

    tree1.join(tree2);

    tree1.visit([](int key, int value) {
        cs::Console::writeLine("Key: ", key);
        cs::Console::writeLine("Value: ", value);
    });

    ASSERT_EQ(10, tree1.root());
    ASSERT_EQ(tree1.size(), 6);
    ASSERT_EQ(tree1.height(), 3);
}
