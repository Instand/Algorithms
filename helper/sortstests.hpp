#ifndef SORTSTESTS_HPP
#define SORTSTESTS_HPP

#include <utils.hpp>

#include <sort/stupidsort.hpp>
#include <sort/bublesort.hpp>
#include <sort/quicksort.hpp>
#include <sort/selectionsort.hpp>
#include <sort/insertionsort.hpp>

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
    class SortsTests {
    public:
        static bool testQuickSort() {
            GENERATE_DATA();

            cs::Console::writeLine("Start Quick sort tests");

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

        static bool testSelectionSort() {
            GENERATE_DATA();

            cs::Console::writeLine("Start Selection sort tests");

            cs::Console::writeLine("Before sort: ");
            cs::Console::print(v);

            cs::selectionSort(v.begin(), v.end());

            cs::Console::writeLine("After sort: ");
            cs::Console::print(v);

            return std::is_sorted(v.begin(), v.end());
        }

        static bool testInsertionSort() {
            GENERATE_DATA();

            cs::Console::writeLine("Start Insertion sort tests");

            cs::Console::writeLine("Before sort: ");
            cs::Console::print(v);

            cs::insertionSort(v.begin(), v.end());

            cs::Console::writeLine("After sort: ");
            cs::Console::print(v);

            return std::is_sorted(v.begin(), v.end());
        }
    };
}

#endif // SORTSTESTS_HPP
