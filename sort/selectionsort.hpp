#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include <iterator>

namespace cs {
    template<typename Iterator>
    void selectionSort(Iterator begin, Iterator end) {
        for (; begin != end; ++begin) {
            Iterator min = begin;

            for (auto b = begin; b != end; ++b) {
                if (*min > *b) {
                    min = b;
                }
            }

            std::iter_swap(min, begin);
        }
    }
}

#endif // SELECTIONSORT_HPP
