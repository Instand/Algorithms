#define TESTING

#include <gtest/gtest.h>

#include <algorithm>

#include <utils.hpp>

#include <structures/forwardlist.hpp>

TEST(ForwardList, TestPushFront) {
    cs::ForwardList<size_t> forwardList;

    for (size_t i = 0; i < 100; ++i) {
        forwardList.pushFront(i);
    }

    cs::Console::print("Forward list elements after push front ", forwardList);
    cs::Console::size(forwardList);

    auto index = forwardList.size() - 1;

    for (const auto& element : forwardList) {
        ASSERT_EQ(index, element);
        --index;
    }
}

TEST(ForwardList, TestPopFront) {
    cs::ForwardList<size_t> list;

    for (size_t i = 0; i < 100; ++i) {
        list.pushFront(i);
    }

    for (size_t i = 0; i < 100; ++i) {
        list.popFront();
    }

    ASSERT_TRUE(list.isEmpty());
}

TEST(ForwardList, TestReverse) {
    constexpr size_t count = 100;

    std::vector<size_t> results;
    results.reserve(count);

    for (size_t i = 0; i < count; ++i) {
        results.push_back(i);
    }

    cs::ForwardList<size_t> list;

    for (size_t i = 0; i < 100; ++i) {
        list.pushFront(i);
    }

    list.reverse();

    size_t index = 0;

    for (auto e : list) {
        ASSERT_EQ(e, results[index++]);
    }
}
