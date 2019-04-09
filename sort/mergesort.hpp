#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>
#include <deque>
#include <iterator>
#include <utility>

namespace cs {
    template <typename Iter>
    void merge(Iter begin, Iter medium, Iter end) {
        std::deque<typename Iter::value_type> temp;

        auto iter = medium;
        for (auto size = std::distance(begin, iter); size > 0; --size, --iter) {
            temp.push_front(*iter);
        }

        for (auto i = std::next(medium); i != end; ++i) {
            temp.push_back(*i);
        }
    }

    template <typename Iterator>
    void mergeSort(Iterator begin, Iterator end) {
        if (begin == end) {
            return;
        }

        auto lenght = std::distance(begin, end);
        Iterator medium = std::next(begin, lenght/2);

        mergeSort(begin, medium);
        mergeSort(std::next(medium), end);

        merge(begin, medium, end);
    }
}

#endif // MERGESORT_HPP
