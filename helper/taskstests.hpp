#ifndef TASKSTESTS_HPP
#define TASKSTESTS_HPP

#include <utils.hpp>
#include <vector>
#include <algorithm>

namespace cs {
    namespace helper {
        template<typename T>
        void removeEverySecondElement(T& container) {
            int size = static_cast<int>(container.size());
            for (int i = size - 1; i > 0; i -= 2) {
                container.erase(std::next(container.begin(), i));
            }
        }

        template<typename T>
        std::vector<T> mergeTwoOrderedVectors(const std::vector<T>& lhs, const std::vector<T>& rhs) {
            std::vector<T> result;
            result.reserve(lhs.size() + rhs.size());

            for (size_t i = 0, j = 0; i < lhs.size() || j < rhs.size(); ) {
                if (i < lhs.size() && j < rhs.size()) {
                    if (lhs[i] < rhs[j]) {
                        result.push_back(lhs[i++]);
                    }
                    else {
                        result.push_back(rhs[j++]);
                    }
                }
                else if (i == lhs.size()) {
                    result.push_back(rhs[j++]);
                }
                else {
                    result.push_back(lhs[i++]);
                }
            }

            return result;
        }
    }

    class TasksTests {
    public:
        static bool removeEverySecondElement() {
            std::vector<int> vector = {
                1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
            };

            std::vector<int> expectedVector = {
                1, 3, 5, 7, 9, 11, 13, 15
            };

            cs::Console::writeLine("Remove every second element test started");
            cs::Console::print(vector);

            helper::removeEverySecondElement(vector);

            cs::Console::writeLine("Element after removing");
            cs::Console::size(vector);
            cs::Console::print(vector);

            return (vector == expectedVector);
        }

        static bool mergeTwoOrderedVectors() {
            std::vector<int> v1 = {
                1, 5, 10, 15, 20, 30, 40
            };

            std::vector<int> v2 = {
                2, 3, 4, 12, 17, 25, 33, 51
            };

            cs::Console::writeLine("Merge two ordered vector test started");

            std::vector<int> merged = helper::mergeTwoOrderedVectors(v1, v2);

            cs::Console::writeLine("Merged vector");
            cs::Console::print(merged);

            return std::is_sorted(merged.begin(), merged.end());
        }
    };
}

#endif // TASKSTESTS_HPP
