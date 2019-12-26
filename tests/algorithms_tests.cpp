#define TESTING

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include <utils.hpp>
#include <algorithms.hpp>

TEST(Algorithms, TestHex) {
    std::vector<uint8_t> bytes = {
        1, 255, 0, 30, 45, 3, 5, 100
    };

    std::string hex = cs::Algorithms::toHex(bytes);
    cs::Console::writeLine("Hex: ");
    cs::Console::writeLine(hex);

    ASSERT_TRUE(cs::Algorithms::isHex(hex));
}

TEST(Algorithms, TestPrime) {
    constexpr size_t n = 100;
    auto primes = cs::Algorithms::prime(n);

    cs::Console::size(primes);
    cs::Console::print(primes);

    for (auto element : primes) {
        ASSERT_TRUE(cs::Algorithms::isPrime(element));
    }
}

TEST(Algorithms, TestFactorial) {
    const int value = 4;
    cs::Console::writeLine("Start factorial tests");

    auto result = cs::Algorithms::factorial(value);
    cs::Console::writeLine("Factorial result is ", result);

    ASSERT_EQ(static_cast<int>(result), (1 * 2 * 3 * 4));
}

TEST(Algorithms, TestSwap) {
    int a = 5;
    int b = 10;

    cs::Algorithms::swap(a, b);

    ASSERT_EQ(a, 10);
    ASSERT_EQ(b, 5);

    std::vector<int> v1 = {
        1, 2, 3
    };

    std::vector<int> v2 = {
        5, 6, 7
    };

    std::vector<int> expected1 = v2;
    std::vector<int> expected2 = v1;

    cs::Algorithms::swap(v1, v2);

    ASSERT_EQ(expected1, v1);
    ASSERT_EQ(expected2, v2);
}
