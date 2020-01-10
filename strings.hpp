#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <cstring>
#include <string>
#include <string_view>

namespace cs {
    struct Strings {
        static bool hasPrefix(std::string_view str, std::string_view substr) {
            return str.size() >= substr.size() && str.substr(0, substr.size()) == substr;
        }

        static bool contains(const std::string& str, const std::string& substr) {
            size_t size = str.size();

            for (size_t i = 0; i < size; ++i) {
                if (hasPrefix({&str[i], size - i}, substr)) {
                    return true;
                }
            }

            return false;
        }

        static bool contains(const char* str, const char* substr) {
            auto haystackSize = std::strlen(str);
            auto needleSize = std::strlen(substr);

            for (size_t i = 0; i < haystackSize; ++i) {
                if (hasPrefix({ str + i, haystackSize - i}, { substr, needleSize })) {
                    return true;
                }
            }

            return false;
        }
    };
}

#endif // STRINGS_HPP
