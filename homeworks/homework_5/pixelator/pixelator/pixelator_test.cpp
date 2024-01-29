#include <gtest/gtest.h>
#include <filesystem>
#include <utility>
#include "pixelator/drawer.hpp"
#include "pixelator/pixelate_image.hpp"

TEST(stb_image_data_view_test, create_empty_view) {
  pixelator::StbImageDataView empty_image{};
  EXPECT_EQ(empty_image.rows(), 0);
  EXPECT_EQ(empty_image.cols(), 0);
  EXPECT_EQ(empty_image.empty(), true);
}

TEST(stb_image_data_view_test, copy_move_semantics) {
  std::filesystem::path image_path{"../../pixelator/test_data/test.png"};
  ASSERT_EQ(std::filesystem::exists(image_path), true);
  pixelator::StbImageDataView image{image_path};
  EXPECT_EQ(image.rows(), 6);
  EXPECT_EQ(image.cols(), 4);
  EXPECT_EQ(image.empty(), false);

  pixelator::StbImageDataView moved_image = std::move(image);
  EXPECT_EQ(moved_image.rows(), 6);
  EXPECT_EQ(moved_image.cols(), 4);
  EXPECT_EQ(moved_image.empty(), false);
}

TEST(DrawerValidationTest, SetFromImage) {
  pixelator::Image image{pixelator::Size{1, 2}};
  image.at(0, 0) = ftxui::Color::Black;
  image.at(0, 1) = ftxui::Color::Red;
  pixelator::Drawer drawer{ftxui::Dimension::Fixed(1)};
  drawer.Set(image);
  EXPECT_EQ(drawer.ToString(),
            std::string{"\x1B[39m\x1B[40m \x1B[39m\x1B[49m"});
}
