#ifndef TASKS_HPP
#define TASKS_HPP

#include <vector>
#include <utility>
#include <algorithm>

namespace cs {
    class Tasks {
    public:
        template<typename T>
        static void removeEverySecondElement(T& container) {
            int size = static_cast<int>(container.size());

            for (int i = size - 1; i > 0; i -= 2) {
                container.erase(std::next(container.begin(), i));
            }
        }

        template<typename T>
        static std::vector<T> mergeTwoOrderedVectors(const std::vector<T>& lhs, const std::vector<T>& rhs) {
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
    };
}

#endif // TASKS_HPP
