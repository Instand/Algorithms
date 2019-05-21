#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <utility>

#include <utils.hpp>

namespace cs {
    class Heap {
    public:
        template<typename Iter>
        static bool checkHeap(Iter begin, Iter end) {
            auto length = std::distance(begin, end);

            for (Iter b = begin; b != end; ++b) {
                auto index = length - std::distance(b, end);
                auto [first, second] = std::make_pair(std::next(begin, (index * 2) + 1), std::next(begin, (index * 2) + 2));

                if (first < end) {
                    if ((*first) > *b) {
                        return false;
                    }
                }

                if (second < end) {
                    if ((*second) > *b) {
                        return false;
                    }
                }
            }

            return true;
        }

        template<typename Iter>
        static void fixUp(Iter begin, Iter end) {
            if (begin == end) {
                return;
            }

            auto e = std::prev(end);
            auto length = std::distance(begin, end);

            while (begin != end) {
                auto index = length - std::distance(e, end);
                auto prev = std::next(begin, (index - 1)/2);

                if ((prev < begin) || (*prev) >= (*e)) {
                    break;
                }

                std::iter_swap(prev, e);
                e = prev;
            }
        }

        template<typename Iter>
        static void fixDown(Iter begin, Iter end) {
            auto length = std::distance(begin, end);
            auto b = begin;

            forever {
                auto distance = std::distance(b, end);
                auto index = length - distance;

                auto k = std::next(begin, index);
                auto j = std::next(begin, (index * 2) + 1);

                if (j >= end || k >= end) {
                    break;
                }

                if ((std::next(j) != end) && (*j < *std::next(j))) {
                    ++j;
                }

                if (!((*k) < (*j))) {
                    break;
                }

                std::iter_swap(k, j);
                b = j;
            }
        }

        template<typename Iter>
        static void makeHeap(Iter begin, Iter end) {
            if (begin == end) {
                return;
            }

            for (auto b = std::prev(end); b >= begin; --b) {
                Heap::fixDown(b, end);
            }
        }
    };
}

#endif // HEAP_HPP
