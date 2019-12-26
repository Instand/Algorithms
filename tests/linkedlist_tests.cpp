#define TESTING

#include <gtest/gtest.h>

#include <algorithm>

#include <utils.hpp>
#include <algorithms.hpp>

#include <structures/linkedlist.hpp>

TEST(LinkedList, PushBack) {
    cs::LinkedList<int> list;
    cs::Console::size(list);

    for (size_t i = 0; i < 10; ++i) {
        list.pushBack(static_cast<int>(i));
    }

    cs::Console::size(list);
    cs::Console::print(list);

    size_t index = 0;
    bool result = true;

    for (const auto& element : list) {
        auto convert = static_cast<size_t>(element);
        if (convert != index) {
            result = false;
        }

        index++;
    }

    cs::Console::size(list);
    ASSERT_TRUE(result);
}

TEST(LinkedList, PushFront) {
    cs::LinkedList<int> list;
    cs::Console::size(list);
    size_t size = 20;

    for (size_t i = 0; i < size; ++i) {
        list.pushFront(static_cast<int>(i));
    }

    cs::Console::size(list);
    cs::Console::print(list);

    size_t index = size - 1;
    bool result = true;

    cs::Algorithms::forEach(list.begin(), list.end(), [&](const size_t element) {
        if (element != index) {
            result = false;
        }

        index--;
    });

    ASSERT_TRUE(result);
}

TEST(LinkedList, Insert) {
    cs::LinkedList<size_t> list;
    cs::Console::size(list);

    size_t size = 20;

    // always insert at the head
    for (size_t i = 0; i < size; ++i) {
        list.insert(list.begin(), i);
    }

    cs::Console::size(list);
    cs::Console::print(list);

    size_t index = size - 1;
    bool result = true;

    for (const auto& element : list) {
        if (element != index) {
            result = false;
        }

        index--;
    }

    ASSERT_TRUE(result);
}

TEST(LinkedList, FindAndRemove) {
    cs::LinkedList<size_t> list;
    size_t size = 20;

    for (size_t i = 0; i < size; ++i) {
        list.pushBack(i);
    }

    cs::Console::size(list);

    auto iterator = std::find(list.begin(), list.end(), 10);
    bool result = true;

    if (iterator == list.end()) {
        result = false;
    }

    // erase middle
    list.erase(iterator);
    cs::Console::size(list);
    cs::Console::print(list);

    if (list.size() != (size - 1)) {
        result = false;
    }

    //erase begin
    list.erase(list.begin());
    cs::Console::size(list);
    cs::Console::print(list);

    //erase end
    auto end = list.end();
    --end;

    list.erase(end);
    cs::Console::size(list);
    cs::Console::print(list);

    if (list.size() != (size - 3)) {
        result = false;
    }

    ASSERT_TRUE(result);
}

TEST(LinkedList, Reverse) {
    cs::LinkedList<size_t> list;
    cs::LinkedList<size_t> expectedList;
    size_t size = 10;

    for (size_t i = 0; i < size; ++i) {
        list.pushBack(i);
        expectedList.pushFront(i);
    }

    cs::Console::writeLine("List before reverse");
    cs::Console::size(list);
    cs::Console::print(list);

    list.reverse();

    cs::Console::writeLine("List after reverse");
    cs::Console::size(list);
    cs::Console::print(list);

    ASSERT_TRUE(std::equal(list.begin(), list.end(), expectedList.begin(), expectedList.end()));
}
