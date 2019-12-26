#define TESTING

#include <gtest/gtest.h>

#include <utils.hpp>

#include <sort/stupidsort.hpp>
#include <sort/bublesort.hpp>
#include <sort/quicksort.hpp>
#include <sort/selectionsort.hpp>
#include <sort/insertionsort.hpp>
#include <sort/mergesort.hpp>
#include <sort/heapsort.hpp>

#include <algorithm>
#include <vector>
#include <functional>

class Sort;

class Collection {
public:
    enum class Type {
        Vector,
        Array
    };

    static auto generate() {
        constexpr size_t size = 20;
        constexpr int min = 0;
        constexpr int max = 10000;

        return cs::Generator::generateCollection<int>(min, max, size);
    }

    using Iter = std::vector<int>::iterator;
    using Func = std::function<void(Iter, Iter)>;

    friend class Sort;
};

class Sort {
public:
    template <Collection::Type type, typename T>
    static bool start(T sort, const std::string& name) {
        auto collection = Collection::generate();

        cs::Console::writeLine("Start ", name, " tests");
        cs::Console::writeLine("Before sort: ");
        cs::Console::print(collection);

        if constexpr (type == Collection::Type::Vector) {
            sort(collection.begin(), collection.end());
        }
        else {
            sort(collection.data(), collection.size());
        }

        cs::Console::writeLine("After sort: ");
        cs::Console::print(collection);

        return std::is_sorted(collection.begin(), collection.end());
    }
};

class SortsTests {
public:
    static bool testQuickSort() {
        return Sort::start<Collection::Type::Vector, Collection::Func>(&cs::quickSort<Collection::Iter>, "Quick sort");
    }

    static bool testBubleSort() {
        return Sort::start<Collection::Type::Vector, Collection::Func>(&cs::bubleSort<Collection::Iter>, "Buble sort");
    }

    static bool testStupidSort() {
        return Sort::start<Collection::Type::Vector, Collection::Func>(&cs::stupidSort<Collection::Iter>, "Stupid sort");
    }

    static bool testSelectionSort() {
        return Sort::start<Collection::Type::Vector, Collection::Func>(&cs::selectionSort<Collection::Iter>, "Selection sort");
    }

    static bool testInsertionSort() {
        return Sort::start<Collection::Type::Vector, Collection::Func>(&cs::insertionSort<Collection::Iter>, "Insertion sort");
    }

    static bool testMergeSort() {
        return Sort::start<Collection::Type::Vector, Collection::Func>(&cs::mergeSort<Collection::Iter>, "Merge sort");
    }

    static bool testHeapSort() {
        return Sort::start<Collection::Type::Vector, Collection::Func>(&cs::heapSort<Collection::Iter>, "Heap sort");
    }
};

TEST(Sort, TestQuickSort) {
    ASSERT_TRUE(SortsTests::testQuickSort());
}

TEST(Sort, TestBubleSort) {
    ASSERT_TRUE(SortsTests::testBubleSort());
}

TEST(Sort, TestStupidSort) {
    ASSERT_TRUE(SortsTests::testStupidSort());
}

TEST(Sort, TestSelectionSort) {
    ASSERT_TRUE(SortsTests::testSelectionSort());
}

TEST(Sort, TestInsertionSort) {
    ASSERT_TRUE(SortsTests::testInsertionSort());
}

TEST(Sort, TestMergeSort) {
    ASSERT_TRUE(SortsTests::testMergeSort());
}

TEST(Sort, TestHeapSort) {
    ASSERT_TRUE(SortsTests::testHeapSort());
}
