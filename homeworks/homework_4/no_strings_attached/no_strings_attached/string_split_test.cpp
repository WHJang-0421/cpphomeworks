#include <no_strings_attached/string_split.h>
#include <gtest/gtest.h>

using std::string_literals::operator""s;

TEST(TestTopic, checkNumberOfChunks) {
  EXPECT_EQ(
      no_strings_attached::Split(
          "Plants are interesting creatures. They have many similarities with us human beings."s,
          " "s, 0)
          .size(),
      0UL);
  EXPECT_EQ(
      no_strings_attached::Split(
          "Plants are interesting creatures. They have many similarities with us human beings."s,
          " "s, 4)
          .size(),
      4UL);
}

TEST(TestTopic, checkEmptySplit) {
  std::vector answer = {""s, "example"s};
  EXPECT_EQ(no_strings_attached::Split(" example"s, " "s), answer);
}

TEST(TestTopic, checkDelimiter) {
  std::vector answer = {""s, "ab"s, "ba"s};
  EXPECT_EQ(no_strings_attached::Split("aaabaaba"s, "aa"s), answer);
}
