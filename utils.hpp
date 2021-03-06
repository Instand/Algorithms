#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <utility>
#include <random>
#include <string>
#include <chrono>
#include <memory>

#define forever for(;;)
#define unused(x) (void)(x)

namespace cs {
    struct Initializer {
        Initializer() {
            std::srand(seed);
        }

        inline static unsigned seed = static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count());
    };

    struct Generator {
        inline static Initializer initializer;

        static int generateRandomValue(int min, int max) {
            static std::default_random_engine engine(Initializer::seed);
            std::uniform_int_distribution<int> distribution(min, max);

            return distribution(engine);
        }

        template<typename T>
        static T generateRandomValue(T min, T max) {
            static std::default_random_engine engine(Initializer::seed);

            if constexpr (std::is_floating_point_v<T>) {
                std::uniform_real_distribution<T> distribution(min, max);
                return static_cast<T>(distribution(engine));
            }

            std::uniform_int_distribution<T> distribution(min, max);
            return static_cast<T>(distribution(engine));
        }

        template<typename T>
        static std::vector<T> generateCollection(T min, T max, size_t count) {
            std::vector<T> container;

            for (size_t i = 0; i < count; ++i) {
                container.push_back(Generator::generateRandomValue<T>(min, max));
            }

            return container;
        }

        template<typename T>
        static std::pair<std::unique_ptr<T[]>, size_t> generateArray(T min, T max, size_t count) {
            std::unique_ptr<T[]> array(new T[count]);

            for (size_t i = 0; i < count; ++i) {
                array[i] = Generator::generateRandomValue<T>(min, max);
            }

            return std::make_pair(std::move(array), count);
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

            std::cout << "[end]" << std::endl;
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
        static void print(const std::string& message, const T& container) {
            std::cout << message << ", size: " << container.size() << ", values ";
            print(container);
        }

        template<typename T>
        static void print(std::shared_ptr<T> container) {
            cs::Console::print(*container.get());
        }

        template <typename T>
        static void size(const T& container) {
            writeLine(typeid (T).name(), " size ", std::size(container));
        }


        template <typename Iter>
        static void print(Iter begin, Iter end) {
            using ValueType = typename Iter::value_type;
            print(std::vector<ValueType>{begin, end});
        }
    };
}

#endif // UTILS_HPP
