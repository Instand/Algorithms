#ifndef STUPIDSORT_HPP
#define STUPIDSORT_HPP

#include <iterator>

// also known as gnome sort

// worst-case O(n^2)
// avarage-case O(n^2)
// best-case O(n)

// memory space O(1)

// not stable

namespace cs {
    template <typename Iterator>
    void stupidSort(Iterator begin, Iterator end) {
        for (Iterator i = begin; std::next(i) != end;) {
            Iterator next = std::next(i);

            if (*i > *next) {
                std::iter_swap(i, next);

                if (i != begin) {
    #ifndef NDEBUG
                    if (std::prev(i) == begin) {
                        i = std::prev(i);
                        continue;
                    }
    #endif
                    i = std::prev(i, 2);
                }
            }

            ++i;
        }
    }
}

#endif // STUPIDSORT_HPP
