#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <utility>
#include <random>
#include <chrono>
#include <string>

namespace cs {
    struct Initializer {
        Initializer() {
            std::srand(seed);
        }

        inline static unsigned seed = static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count());
    };

    struct Generator {
        enum Style {
            CStyle,
            CppStyle
        };

        static int generateRandomValue(int min, int max, Style style = Style::CppStyle) {
            [[maybe_unused]] static Initializer initializer;

            if (style == Style::CppStyle) {
                static std::default_random_engine engine(Initializer::seed);
                std::uniform_int_distribution<int> distribution(min, max);
                return distribution(engine);
            }

            return (min + (std::rand() % (max - min + 1)));
        }
    };

    namespace helper {
        template <typename T>
        struct is_pair : public std::false_type {};

        template <typename T, typename K>
        struct is_pair<std::pair<T, K>> : public std::true_type {};

        template <typename T>
        void print(const T& container, std::false_type) {
            for (const auto& element : container) {
                std::cout << element << " ";
            }

            std::cout << std::endl;
        }

        template <typename T>
        void print(const T& container, std::true_type) {
            for (const auto& [key, value] : container) {
                std::cout << "Key " << key << ", value " << value << std::endl;
            }

            std::cout << std::endl;
        }
    }

    class Console {
    public:
        template <typename... Args>
        static void writeLine(Args&&... args) {
            (std::cout << ... << args) << std::endl;
        }

        template <typename T>
        static void print(const T& container) {
            helper::print(container, helper::is_pair<typename T::value_type>());
        }

        template <typename T>
        static void size(const T& container) {
            writeLine(typeid (T).name(), " size ", std::size(container));
        }
    };

    struct Benchmark {
        template <typename Func>
        static bool run(Func f) {
            auto now = std::chrono::steady_clock::now();
            cs::Console::writeLine("\nStart benchmark");

            // entity
            auto result = f();

            auto difference = std::chrono::steady_clock::now() - now;
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(difference);

            static const char* title = "Benchmark finished, time in";

            if (duration.count() != 0) {
                cs::Console::writeLine(title, " ms ", duration.count());
            }
            else {
                cs::Console::writeLine(title, " ns ", std::chrono::duration_cast<std::chrono::nanoseconds>(difference).count());
            }

            return result;
        }
    };
}

#endif // UTILS_HPP
