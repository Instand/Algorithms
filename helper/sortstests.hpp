#ifndef SORTSTESTS_HPP
#define SORTSTESTS_HPP

#include <utils.hpp>

#include <sort/stupidsort.hpp>
#include <sort/bublesort.hpp>
#include <sort/quicksort.hpp>
#include <sort/selectionsort.hpp>
#include <sort/insertionsort.hpp>
#include <sort/mergesort.hpp>

#include <algorithm>
#include <vector>
#include <functional>

namespace cs {
    class Sort;
    class SortsTests;

    class Collection {
    public:
        using iterator = std::vector<int>::iterator;
        using array = std::vector<int>::value_type[];

    private:
        static std::vector<int> generate() {
            constexpr size_t size = 20;
            constexpr int min = 0;
            constexpr int max = 10000;

            std::vector<int> result;
            result.reserve(size);

            for (size_t i = 0; i < size; ++i) {
                result.push_back(cs::Generator::generateRandomValue(min, max));
            }

            return result;
        }

        friend class Sort;
    };

    class Sort {
    public:
        template<typename T, typename U = typename Collection::iterator>
        static bool start(T sort, const std::string& name) {
            auto collection = Collection::generate();

            cs::Console::writeLine("Start ", name, " tests");

            cs::Console::writeLine("Before sort: ");
            cs::Console::print(collection);

            if constexpr (std::is_array_v<U>) {
                sort(collection.data(), collection.size());
            }
            else {
                sort(collection.begin(), collection.end());
            }

            cs::Console::writeLine("After sort: ");
            cs::Console::print(collection);

            return std::is_sorted(collection.begin(), collection.end());
        }
    };

    class SortsTests {
        using Iter = Collection::iterator;
        using Func = std::function<void(Iter, Iter)>;

    public:
        static bool testQuickSort() {
            return Sort::start<Func>(&cs::quickSort<Iter>, "Quick sort");
        }

        static bool testBubleSort() {
            return Sort::start<Func>(&cs::bubleSort<Iter>, "Buble sort");
        }

        static bool testStupidSort() {
            return Sort::start<Func>(&cs::stupidSort<Iter>, "Stupid sort");
        }

        static bool testSelectionSort() {
            return Sort::start<Func>(&cs::selectionSort<Iter>, "Selection sort");
        }

        static bool testInsertionSort() {
            return Sort::start<Func>(&cs::insertionSort<Iter>, "Insertion sort");
        }

        static bool testMergeSort() {
            return Sort::start<Func>(&cs::mergeSort<Iter>, "Merge sort");
        }
    };
}

#endif // SORTSTESTS_HPP
