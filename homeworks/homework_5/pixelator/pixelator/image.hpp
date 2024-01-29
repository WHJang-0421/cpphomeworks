#pragma once
#include <vector>
#include "pixelator/stb_image_data_view.hpp"

namespace pixelator {
class Image {
 public:
  Image();
  Image(int rows, int cols);
  Image(Size size);

  bool empty() const;
  int rows() const;
  int cols() const;
  pixelator::Size size() const;
  const ftxui::Color& at(int query_row, int query_col) const;
  ftxui::Color& at(int query_row, int query_col);

 private:
  std::vector<ftxui::Color> image_data_{};
  int rows_{};
  int cols_{};
  bool empty_{true};
};
}  // namespace pixelator
