#define TESTING

#include <gtest/gtest.h>

#include <algorithm>
#include <utils.hpp>

#include <structures/priorityqueue.hpp>

TEST(PriorityQueue, TestPush) {
    cs::PriorityQueue<size_t> queue;

    size_t value1 = 10;
    queue.push(value1);

    cs::Console::writeLine("Priority queue top element ", queue.top());

    ASSERT_EQ(queue.top(), value1);

    size_t value2 = 25;
    queue.push(value2);

    cs::Console::writeLine("Priority queue top element ", queue.top());

    ASSERT_EQ(queue.top(), value2);

    size_t value3 = 39;
    queue.push(value3);

    cs::Console::writeLine("Priority queue top element ", queue.top());

    ASSERT_EQ(queue.top(), value3);

    size_t value4 = 56;
    queue.push(value4);

    cs::Console::writeLine("Priority queue top element ", queue.top());

    ASSERT_EQ(queue.top(), value4);

    size_t value5 = 19424;
    queue.push(value5);

    cs::Console::writeLine("Priority queue top element ", queue.top());

    ASSERT_EQ(queue.top(), value5);
    ASSERT_TRUE(!queue.isEmpty());
}

TEST(PriorityQueue, TestPop) {
    constexpr size_t count = 20;
    constexpr int min = 0;
    constexpr int max = 10000;

    cs::PriorityQueue<int> queue;

    for (size_t i = 0; i < count; ++i) {
        queue.push(cs::Generator::generateRandomValue(min, max));
    }

    cs::Console::print("Priority queue values after push", queue);

    while (!queue.isEmpty()) {
        auto top = queue.top();
        auto expectedTop = *std::max_element(queue.begin(), queue.end());

        cs::Console::writeLine("Priority queue top ", top, ", expected top ", expectedTop);
        cs::Console::print("Priority queue values after pop", queue);

        ASSERT_EQ(expectedTop, top);

        queue.pop();
    }
}
