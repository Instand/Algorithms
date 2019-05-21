#ifndef PRIORITYQUEUETESTS_HPP
#define PRIORITYQUEUETESTS_HPP

#include <algorithm>
#include <utils.hpp>
#include <structures/priorityqueue.hpp>

namespace cs {
    class PriorityQueueTests {
    public:
        static bool testPush() {
            cs::PriorityQueue<size_t> queue;

            size_t value1 = 10;
            queue.push(value1);

            cs::Console::writeLine("Priority queue top element ", queue.top());

            if (queue.top() != value1) {
                return false;
            }

            size_t value2 = 25;
            queue.push(value2);

            cs::Console::writeLine("Priority queue top element ", queue.top());

            if (queue.top() != value2) {
                return false;
            }

            size_t value3 = 39;
            queue.push(value3);

            cs::Console::writeLine("Priority queue top element ", queue.top());

            if (queue.top() != value3) {
                return false;
            }

            size_t value4 = 56;
            queue.push(value4);

            cs::Console::writeLine("Priority queue top element ", queue.top());

            if (queue.top() != value4) {
                return false;
            }

            size_t value5 = 19424;
            queue.push(value5);

            cs::Console::writeLine("Priority queue top element ", queue.top());

            if (queue.top() != value5) {
                return false;
            }

            if (queue.isEmpty()) {
                return false;
            }

            return true;
        }

        static bool testPop() {
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

                if (expectedTop != top) {
                    return false;
                }

                queue.pop();
            }

            return true;
        }
    };
}

#endif // PRIORITYQUEUETESTS_HPP
