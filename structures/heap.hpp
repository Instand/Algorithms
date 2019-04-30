#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <vector>
#include <utils.hpp>

namespace cs {
    class Heap {
    public:
        template<typename Iter>
        static void fixUp(Iter begin, Iter end) {
            end = std::prev(end);

            while (begin != end) {
                auto length = std::distance(begin, std::next(end));
                auto prev = std::prev(end, length/2);

                if ((prev < begin) || (*prev) >= (*end)) {
                    break;
                }

                std::iter_swap(prev, end);
                end = prev;
            }
        }

        template<typename Iter>
        static void fixDown(Iter begin, Iter end) {
            auto length = std::distance(begin, end);

            forever {
                auto distance = std::distance(begin, end);
                auto index = length - distance;

                auto k = std::next(begin, index);
                auto j = std::next(begin, (index * 2) + 1);

                if (j >= end) {
                    break;
                }

                if (j < end && (*j < *std::next(j))) {
                    ++j;
                }

                if (!((*k) < (*j))) {
                    break;
                }

                std::iter_swap(k, j);
                begin = j;
            }
        }
    };
}

#endif // PRIORITYQUEUE_HPP
