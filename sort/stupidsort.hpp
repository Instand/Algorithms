#ifndef STUPIDSORT_HPP
#define STUPIDSORT_HPP

#include <iterator>

namespace cs {
    // also known as gnome sort
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
