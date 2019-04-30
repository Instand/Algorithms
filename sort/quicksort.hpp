#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <utility>
#include <iterator>

// worst-case O(n^2)
// avarage-case O(n log n)
// best-case O(n log n)

// memory space O(log n)

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

    namespace array {
        template <typename T>
        size_t hoare(T array[], size_t left, size_t right) {
            size_t l = left;
            size_t r = right;
            size_t p = r--;

            while (l <= r) {
                if (array[l] < array[p]) {
                    ++l;
                }
                else {
                    while (l <= r) {
                    }
                }
            }
        }

        template <typename T>
        void quickSortImpl(T array[], size_t left, size_t right) {
            if (left >= right) {
                return;
            }

            size_t p = hoare(array, left, right);

            quickSortImpl(array, left, p - 1);
            quickSortImpl(array, p + 1, right);
        }

        template <typename T>
        void quickSort(T array[], size_t size) {
            quickSortImpl(array, 0, size);
        }
    }  // namespace array
}

#endif // QUICKSORT_HPP
