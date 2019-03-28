#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <iterator>
#include <utility>

namespace cs {
    template <typename Iterator>
    void mergeSort(Iterator begin, Iterator end) {
        if (begin == end) {
            return;
        }

        Iterator medium = std::next(begin, std::distance(begin, end));
    }
}

#endif // MERGESORT_HPP
