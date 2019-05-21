#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <structures/heap.hpp>

// worst-case O(n log n)
// avarage-case O(n log n)
// best-case O(n log n)

// memory space O(1)

// not stable

namespace cs {
    template <typename Iter>
    void heapSort(Iter begin, Iter end) {
        if (begin == end) {
            return;
        }

        Heap::makeHeap(begin, end);

        for (auto e = std::prev(end); e >= begin; --e) {
            std::iter_swap(begin, e);
            Heap::fixDown(begin, e);
        }
    }
}

#endif // HEAPSORT_HPP
