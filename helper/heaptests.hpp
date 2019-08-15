#ifndef HEAPTESTS_HPP
#define HEAPTESTS_HPP

#include <vector>
#include <algorithm>

#include <utils.hpp>
#include <structures/heap.hpp>

namespace cs {
    class HeapTests {
    public:
        static bool testHeapCreation() {
            auto vector = createHeap();
            return Heap::checkHeap(vector.begin(), vector.end());
        }

        static bool testMakeHeap() {
            constexpr size_t count = 10;
            constexpr int min = 0;
            constexpr int max = 1000;

            cs::Console::writeLine("Make heap test started");

            auto container = Generator::generateCollection<int>(min, max, count);

            cs::Heap::makeHeap(container.begin(), container.end());

            cs::Console::print(container);
            cs::Console::writeLine("Make heap test finished");

            return Heap::checkHeap(container.begin(), container.end());
        }

        static bool testFixUp() {
            cs::Console::writeLine("Fix up test started");

            std::vector<int> v = createHeap();

            cs::Console::writeLine("Fix up test finished");
            cs::Console::print(v);

            const auto max = std::max_element(v.begin(), v.end());
            cs::Console::writeLine("Max real ", *max, ", front max ", v.front());

            return (*max) == v.front();
        }

        static bool testFixDown() {
            cs::Console::writeLine("Fix down test started");

            std::vector<int> v = createHeap();

            while (!v.empty()) {
                const auto realMax = *std::max_element(v.begin(), v.end());
                const auto max = v.front();

                cs::Console::writeLine("Real max element ", realMax, ", heap max element ", max);
                cs::Console::print(v);
                cs::Console::size(v);

                if (realMax != max) {
                    return false;
                }

                std::iter_swap(v.begin(), std::prev(v.end()));
                v.pop_back();

                cs::Console::print("After swap", v);

                Heap::fixDown(v.begin(), v.end());

                cs::Console::print("After fix down", v);
            }

            cs::Console::writeLine("Fix down test finished");
            return true;
        }

    private:
        static std::vector<int> createHeap(int maxValue = 100) {
            std::vector<int> heap;
            constexpr size_t size = 20;

            for (size_t i = 0; i < size; ++i) {
                heap.push_back(cs::Generator::generateRandomValue(0, maxValue));
                Heap::fixUp(heap.begin(), heap.end());
            }

            cs::Console::print("Heap created", heap);
            return heap;
        }
    };
}

#endif // HEAPTESTS_HPP
