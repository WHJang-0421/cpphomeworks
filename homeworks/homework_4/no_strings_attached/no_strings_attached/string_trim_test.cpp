#include <no_strings_attached/string_trim.h>
#include <gtest/gtest.h>

using std::string_literals::operator""s;

TEST(TestTopic2, checkTrimDirection) {
    EXPECT_EQ(no_strings_attached::Trim("  hello "s, ' ', no_strings_attached::Side::kLeft), "hello "s);
    EXPECT_EQ(no_strings_attached::Trim("  hello "s, ' ', no_strings_attached::Side::kRight), "  hello"s);
}

TEST(TestTopic2, checkTrimDelimiter) {
    EXPECT_EQ(no_strings_attached::Trim("helloh "s, 'h', no_strings_attached::Side::kBoth), "elloh "s);
}
