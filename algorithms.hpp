#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <utility>
#include <vector>
#include <iterator>

namespace cs {
    struct Algorithms {
        template <typename Iterator, typename Func>
        static void forEach(Iterator begin, Iterator end, Func func) {
            while (begin != end) {
                func(*begin);
                ++begin;
            }
        }

        template <typename T, typename K>
        static void copy(T begin, T end, K to) {
            while (begin != end) {
                *(to++) = *(begin++);
            }
        }

        template <typename T, typename K, typename Func>
        static void copyIf(T begin, T end, K to, Func func) {
            while (begin != end) {
                if (func(*begin, *end)) {
                    *(to++) = *begin;
                }

                ++begin;
            }
        }

        template <typename T>
        static void swap(T& lhs, T& rhs) {
            T temp = std::move(lhs);
            lhs = std::move(rhs);
            rhs = std::move(temp);
        }

        static bool isHex(const std::string& str) {
            return (str.size()) > 2 &&
                   (str.find_first_not_of("0123456789ABCDEF") == std::string::npos);
        }

        template <typename T>
        static std::string toHex(const T& t) {
            static const char* map = "0123456789ABCDEF";

            std::string result;
            result.reserve(t.size() * 2);

            for (const auto& byte : t) {
                result.push_back(map[byte >> 4]);
                result.push_back(map[byte & 0x0F]);
            }

            return result;
        }

        static std::vector<size_t> prime(size_t n) {
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

        static bool isPrime(size_t value) {
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

        static size_t factorial(size_t value) {
            size_t result = 1;

            for (size_t i = 1; i <= value; ++i) {
                result *= i;
            }

            return result;
        }

        static size_t recursiveFactorial(size_t value) {
            if (value <= 1) {
                return 1ul;
            }

            return value * recursiveFactorial(value - 1);
        }
    };
}

#endif // ALGORITHMS_HPP
