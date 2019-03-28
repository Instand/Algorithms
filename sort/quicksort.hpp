#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <utility>
#include <iterator>

// worst-case O(n^2)
// avarage-case O(n log n)
// best-case O(n log n)

// memory space O(n log n)

// not stable

namespace cs {
    template <typename Iterator>
    std::pair<Iterator, Iterator> hoarePartition(Iterator begin, Iterator end) {
        Iterator b = begin;
        Iterator e = end;
        Iterator pivot = b++;

        while (b != e) {
            if (*b < *pivot) {
                ++b;
            }
            else {
                while ((b != --e) && (*pivot < *e));
                std::iter_swap(b, e);
            }
        }

        --b;
        std::iter_swap(begin, b);

        return std::make_pair(b, e);
    }

    template <typename Iterator>
    void quickSort(Iterator begin, Iterator end) {
      if (begin != end) {
        auto [b, e] = hoarePartition(begin, end);
        quickSort(begin, b);
        quickSort(e, end);
      }
    }
}

#endif // QUICKSORT_HPP
