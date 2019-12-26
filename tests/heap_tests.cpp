#define TESTING

#include <gtest/gtest.h>

#include <vector>
#include <algorithm>

#include <utils.hpp>

#include <structures/heap.hpp>

static std::vector<int> createHeap(int maxValue = 100) {
    std::vector<int> heap;
    constexpr size_t size = 20;

    for (size_t i = 0; i < size; ++i) {
        heap.push_back(cs::Generator::generateRandomValue(0, maxValue));
        cs::Heap::fixUp(heap.begin(), heap.end());
    }

    cs::Console::print("Heap created", heap);
    return heap;
}

TEST(Heap, TestHeapCreation) {
    auto vector = createHeap();
    ASSERT_TRUE(cs::Heap::checkHeap(vector.begin(), vector.end()));
}

TEST(Heap, TestMakeHeap) {
    constexpr size_t count = 10;
    constexpr int min = 0;
    constexpr int max = 1000;

    auto container = cs::Generator::generateCollection<int>(min, max, count);

    cs::Heap::makeHeap(container.begin(), container.end());
    cs::Console::print(container);

    ASSERT_TRUE(cs::Heap::checkHeap(container.begin(), container.end()));
}

TEST(Heap, TestFixUp) {
    std::vector<int> v = createHeap();
    cs::Console::print(v);

    const auto max = std::max_element(v.begin(), v.end());
    cs::Console::writeLine("Max real ", *max, ", front max ", v.front());

    ASSERT_EQ((*max), v.front());
}

TEST(Heap, TestFixDown) {
    std::vector<int> v = createHeap();

    while (!v.empty()) {
        const auto realMax = *std::max_element(v.begin(), v.end());
        const auto max = v.front();

        cs::Console::writeLine("Real max element ", realMax, ", heap max element ", max);
        cs::Console::print(v);
        cs::Console::size(v);

        ASSERT_EQ(realMax, max);

        std::iter_swap(v.begin(), std::prev(v.end()));
        v.pop_back();

        cs::Console::print("After swap", v);

        cs::Heap::fixDown(v.begin(), v.end());

        cs::Console::print("After fix down", v);
    }
}
