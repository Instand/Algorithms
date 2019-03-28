#ifndef BUBLESORT_HPP
#define BUBLESORT_HPP

#include <iterator>

// worst-case O(n^2)
// avarage-case O(n^2)
// best-case O(n)

// memory space O(1)

// not stable

namespace cs {
    template <typename Iterator>
    void bubleSort(Iterator begin, Iterator end) {
        auto e = end;
        for (Iterator i = begin; std::next(i) != end; ++i) {
            for (Iterator j = begin; j != std::prev(e); ++j) {
                Iterator next = std::next(j);

                if (*j > *next) {
                    std::iter_swap(j, next);
                }
            }
        }
    }
}

#endif // BUBLESORT_HPP
