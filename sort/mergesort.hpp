#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>
#include <iterator>
#include <utility>

// worst-case O(n log m)
// avarage-case O(n log n)
// best-case O(n log n)

// memory space O(n)

// stable

namespace cs {
    template <typename Iter>
    void merge(Iter begin, Iter medium, Iter end) {
        using Value = typename Iter::value_type;

        std::vector<Value> first(begin, medium);
        std::vector<Value> second(medium, end);

        auto firstBegin = first.begin();
        auto secondBegin = second.begin();

        for (auto iter = begin; iter != end; ++iter) {
            if (firstBegin == first.end()) {
                std::iter_swap(iter, secondBegin++);
            }
            else if (secondBegin == second.end()) {
                std::iter_swap(iter, firstBegin++);
            }
            else if ((*firstBegin) < (*secondBegin)) {
                std::iter_swap(firstBegin++, iter);
            }
            else {
                std::iter_swap(secondBegin++, iter);
            }
        }
    }

    template <typename Iterator>
    void mergeSort(Iterator begin, Iterator end) {
        auto lenght = std::distance(begin, end);

        if (lenght < 2) {
            return;
        }

        Iterator medium = std::next(begin, lenght/2);

        mergeSort(begin, medium);
        mergeSort(medium, end);

        merge(begin, medium, end);
    }
}

#endif // MERGESORT_HPP
