#define TESTING

#include <gtest/gtest.h>

#include <utils.hpp>
#include <vector>
#include <algorithm>

#include <tasks.hpp>

TEST(Task, TestRemoveEverySecondElement) {
    std::vector<int> vector = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
    };

    std::vector<int> expectedVector = {
        1, 3, 5, 7, 9, 11, 13, 15
    };

    cs::Console::print(vector);

    cs::Tasks::removeEverySecondElement(vector);

    cs::Console::writeLine("Element after removing");
    cs::Console::size(vector);
    cs::Console::print(vector);

    ASSERT_EQ(vector, expectedVector);

    std::vector<int> data = {
        1, 2, 3, 4, 5, 6, 7, 8, 9
    };

    std::vector<int> expectedData = {
        1, 3, 5, 7, 9
    };

    cs::Tasks::removeEverySecondElement(data);

    cs::Console::writeLine("Element after removing");
    cs::Console::size(data);
    cs::Console::print(data);

    ASSERT_EQ(data, expectedData);
}

TEST(Task, TestMergeTwoOrderedVectors) {
    std::vector<int> v1 = {
        1, 5, 10, 15, 20, 30, 40
    };

    std::vector<int> v2 = {
        2, 3, 4, 12, 17, 25, 33, 51
    };

    std::vector<int> merged = cs::Tasks::mergeTwoOrderedVectors(v1, v2);

    cs::Console::writeLine("Merged vector");
    cs::Console::print(merged);

    ASSERT_TRUE(std::is_sorted(merged.begin(), merged.end()));
}
