#include "pixelator/image.hpp"

namespace pixelator {
Image::Image() {}
Image::Image(int rows, int cols)
    : image_data_(rows * cols), rows_(rows), cols_(cols), empty_(false) {}
Image::Image(Size size): Image(size.rows, size.cols) {}

bool Image::empty() const { return empty_; }
int Image::rows() const { return rows_; }
int Image::cols() const { return cols_; }
pixelator::Size Image::size() const { return {rows(), cols()}; }
ftxui::Color& Image::at(int query_row, int query_col) {
  return image_data_.at(query_row * cols_ + query_col);
}
const ftxui::Color& Image::at(int query_row, int query_col) const {
  return image_data_.at(query_row * cols_ + query_col);
}
}  // namespace pixelator
