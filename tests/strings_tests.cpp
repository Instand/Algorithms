#define TESTING

#include <gtest/gtest.h>

#include <utils.hpp>
#include <vector>
#include <algorithm>

#include <strings.hpp>

// Haystack used from J.K. Rowling, Harry Potter and the sorcerer's stone (c)

TEST(Strings, TestDefaultSearch) {
    const std::string data = "Then something happened which made him jump about a foot\
    in the air – several people behind him screamed.";
    const std::string substr = "foot";

    ASSERT_TRUE(cs::Strings::contains(data, substr));
}

TEST(Strings, TestDefaultFailedSearch) {
    const std::string data = "R(Harry gripped the edges of the stool and thought, ‘Not\
           Slytherin, not Slytherin.’)";
    const std::string substr = "Hermione";

    ASSERT_FALSE(cs::Strings::contains(data, substr));
}

TEST(Strings, TestCstringDefaultSearch) {
    ASSERT_TRUE(cs::Strings::contains("As Harry stepped forward, whispers suddenly broke out like\
                                      little hissing fires all over the hall.", "fires"));
}

TEST(Strings, TestCstringDefaultFailedSearch) {
    ASSERT_FALSE(cs::Strings::contains("Harry heard the hat shout the last word to the whole Hall. He\
                                       took off the hat and walked shakily towards the Gryffindor table.", "muggle"));
}
