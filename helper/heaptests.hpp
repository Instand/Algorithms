#ifndef HEAPTESTS_HPP
#define HEAPTESTS_HPP

#include <vector>
#include <algorithm>

#include <utils.hpp>
#include <structures/heap.hpp>

namespace cs {
    class HeapTests {
    public:
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

                v.pop_back();
            }

            cs::Console::writeLine("Fix down test finished");
            return true;
        }

    private:
        static std::vector<int> createHeap() {
            std::vector<int> heap;
            constexpr size_t size = 10;

            for (size_t i = 0; i < size; ++i) {
                heap.push_back(cs::Generator::generateRandomValue(0, 100));
                Heap::fixUp(heap.begin(), heap.end());
            }

            cs::Console::print("Heap created", heap);
            return heap;
        }
    };
}

#endif // HEAPTESTS_HPP
