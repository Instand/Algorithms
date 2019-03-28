#ifndef BUBLESORT_HPP
#define BUBLESORT_HPP

#include <iterator>

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
