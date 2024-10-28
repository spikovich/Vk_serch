#include <gtest/gtest.h>
#include <string>
#include <unordered_map>

// Function to be tested
bool compare(const std::string& s1, const std::string& s2)
{
    if (s1.size() != s2.size() || s1.empty() || s2.empty()) {
        return false;
    }
    std::unordered_map<char, char> letters, used;
    for (int i = 0; i < s1.size(); ++i) {
        if (letters.count(s1[i]) == 0) {
            if (used.count(s2[i]) == 0) {
                letters[s1[i]] = s2[i];
                used[s2[i]] = s1[i];
            } else {
                return false;
            }
        } else {
            if (letters[s1[i]] != s2[i]) {
                return false;
            }
        }
    }
    return true;
}

// Test cases
TEST(IsomorphicStringsTest, BasicTests) {
    EXPECT_TRUE(compare("egg", "add"));
    EXPECT_FALSE(compare("foo", "bar"));
    EXPECT_TRUE(compare("paper", "title"));
}

TEST(IsomorphicStringsTest, EdgeCases) {
    EXPECT_FALSE(compare("foooww", "baaarr!"));
    EXPECT_FALSE(compare("fxooowf", "baaarr"));
    EXPECT_FALSE(compare("fxooowf", "byaaary"));
}

TEST(IsomorphicStringsTest, EmptyStrings) {
    EXPECT_FALSE(compare("", ""));
    EXPECT_FALSE(compare("a", ""));
    EXPECT_FALSE(compare("", "a"));
}

TEST(IsomorphicStringsTest, SingleCharacterStrings) {
    EXPECT_TRUE(compare("a", "a"));
    EXPECT_FALSE(compare("a", "b"));
}

TEST(IsomorphicStringsTest, DifferentLengths) {
    EXPECT_FALSE(compare("abc", "ab"));
    EXPECT_FALSE(compare("a", "ab"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}