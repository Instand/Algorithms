#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <utility>
#include <vector>
#include <iterator>

#define forever for (;;)

namespace cs {
    // go to each element
    template <typename Iterator, typename Func>
    void forEach(Iterator begin, Iterator end, Func func) {
        while (begin != end) {
            func(*begin);
            ++begin;
        }
    }

    template <typename T, typename K>
    void copy(T begin, T end, K to) {
        while (begin != end) {
            *(to++) = *(begin++);
        }
    }

    template <typename T, typename K, typename Func>
    void copyIf(T begin, T end, K to, Func func) {
        while (begin != end) {
            if (func(*begin, *end)) {
                *(to++) = *begin;
            }

            ++begin;
        }
    }

    template <typename T>
    void swap(T& lhs, T& rhs) {
        T temp = std::move(lhs);
        lhs = std::move(rhs);
        rhs = std::move(temp);
    }

    bool isHex(const std::string& str) {
        return (str.size()) > 2 &&
               (str.find_first_not_of("0123456789ABCDEF") == std::string::npos);
    }

    template <typename T>
    std::string toHex(const T& t) {
        static const char* map = "0123456789ABCDEF";

        std::string result;
        result.reserve(t.size() * 2);

        for (const auto& byte : t) {
            result.push_back(map[byte >> 4]);
            result.push_back(map[byte & 0x0F]);
        }

        return result;
    }

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

    std::vector<size_t> prime(size_t n) {
        std::vector<bool> primes(n, true);
        primes[0] = false;
        primes[1] = false;

        for (size_t i = 0; i < n; ++i) {
            if (primes[i]) {
                for (size_t j = 2; i*j < n; ++j) {
                    primes[i*j] = false;
                }
            }
        }

        std::vector<size_t> result;
        size_t i = 0;

        forEach(primes.begin(), primes.end(), [&](const auto& element) {
            auto index = i++;
            if (element) {
                result.push_back(index);
            }
        });

        return result;
    }

    bool isPrime(size_t value) {
      if (value <= 1) {
          return false;
      }

      if (value == 2) {
          return true;
      }

      if (value % 2 == 0) {
          return false;
      }

      for (size_t i = 3; i * i < value; ++i) {
          if (value % i == 0) {
              return false;
          }
      }

      return true;
    }

    size_t factorial(size_t value) {
        size_t result = 1;

        for (size_t i = 1; i <= value; ++i) {
            result *= i;
        }

        return result;
    }

    size_t recursiveFactorial(size_t value) {
        if (value <= 1) {
            return 1ul;
        }

        return value * recursiveFactorial(value - 1);
    }

    template <typename Iterator>
    void mergeSort(Iterator begin, Iterator end) {
        if (begin == end) {
            return;
        }

        Iterator medium = std::next(begin, std::distance(begin, end));
    }
}

#endif // ALGORITHMS_HPP
