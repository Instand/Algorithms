#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <iterator>

// worst-case O(n^2)
// avarage-case O(n^2)
// best-case O(n)

// memory space O(1)

// stable

namespace cs {
    template<typename Iter>
    void insertionSort(Iter begin, Iter end) {
        for (auto iter = begin; iter != end; ++iter) {
            for (auto i = iter; i != begin && (*i) < (*std::prev(i)); --i) {
                std::iter_swap(i, std::prev(i));
            }
        }
    }
}

#endif // INSERTIONSORT_HPP
