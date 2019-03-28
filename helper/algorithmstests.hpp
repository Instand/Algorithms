#ifndef ALGORITHMSTESTS_HPP
#define ALGORITHMSTESTS_HPP

#include <algorithms.hpp>
#include <utils.hpp>

#include <sort/stupidsort.hpp>
#include <sort/bublesort.hpp>
#include <sort/quicksort.hpp>

#include <algorithm>
#include <vector>

#define GENERATE_DATA()\
    constexpr size_t size = 20;\
    constexpr int min = 0;\
    constexpr int max = 10000;\
    std::vector<int> v;\
    v.reserve(size);\
    for (size_t i = 0; i < size; ++i) {\
        v.push_back(cs::Generator::generateRandomValue(min, max));\
    }\

namespace cs {
    class AlgorithmsTests {
    public:
        static bool testQuickSort() {
            GENERATE_DATA();

            cs::Console::writeLine("Before sort: ");
            cs::Console::print(v);

            cs::quickSort(v.begin(), v.end());

            cs::Console::writeLine("After sort: ");
            cs::Console::print(v);

            return std::is_sorted(v.begin(), v.end());
        }

        static bool testBubleSort() {
            GENERATE_DATA();

            cs::Console::writeLine("Start Buble sort tests");

            cs::Console::writeLine("Before sort: ");
            cs::Console::print(v);

            cs::bubleSort(v.begin(), v.end());

            cs::Console::writeLine("After sort: ");
            cs::Console::print(v);

            return std::is_sorted(v.begin(), v.end());
        }

        static bool testStupidSort() {
            GENERATE_DATA();

            cs::Console::writeLine("Start Stupid sort tests");

            cs::Console::writeLine("Before sort: ");
            cs::Console::print(v);

            cs::stupidSort(v.begin(), v.end());

            cs::Console::writeLine("After sort: ");
            cs::Console::print(v);

            return std::is_sorted(v.begin(), v.end());
        }

        static bool testHex() {
            std::vector<uint8_t> bytes = {
                1, 255, 0, 30, 45, 3, 5, 100
            };

            std::string hex = cs::toHex(bytes);
            cs::Console::writeLine("Hex: ");
            cs::Console::writeLine(hex);

            return cs::isHex(hex);
        }

        static bool testPrime() {
            constexpr size_t n = 100;

            cs::Console::writeLine("Start primes tests");
            auto primes = cs::prime(n);

            cs::Console::size(primes);
            cs::Console::print(primes);

            for (auto element : primes) {
                if (!cs::isPrime(element)) {
                    return false;
                }
            }

            return true;
        }

        static bool testFactorial() {
            const int value = 4;
            cs::Console::writeLine("Start factorial tests");

            auto result = cs::factorial(value);
            cs::Console::writeLine("Factorial result is ", result);

            return static_cast<int>(result) == (1 * 2 * 3 * 4);
        }

        static bool testSwap() {
            int a = 5;
            int b = 10;

            cs::Console::writeLine("Swap test started");
            cs::swap(a, b);

            if (a != 10 || b != 5) {
                cs::Console::writeLine("Swap values failed");
                return false;
            }

            std::vector<int> v1 = {
                1, 2, 3
            };

            std::vector<int> v2 = {
                5, 6, 7
            };

            std::vector<int> expected1 = v2;
            std::vector<int> expected2 = v1;

            cs::swap(v1, v2);

            if (expected1 != v1 || expected2 != v2) {
                cs::Console::writeLine("Sawap vectors failed");
                return false;
            }

            return true;
        }
    };
}

#endif // ALGORITHMSTESTS_HPP
