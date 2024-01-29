#pragma once
#include <filesystem>
#include "ftxui/screen/color.hpp"

namespace pixelator {
typedef struct _Size {
  int row;
  int col;
} Size;
class StbImageDataView {
 public:
  StbImageDataView(std::filesystem::path image_path);
  StbImageDataView();
  StbImageDataView(StbImageDataView&& other);
  ~StbImageDataView();
  StbImageDataView& operator=(StbImageDataView&& other);

  Size size() const;
  int rows() const;
  int cols() const;
  bool empty() const;
  ftxui::Color at(int query_row, int query_col) const;

 private:
  unsigned char* image_data_ = nullptr;
  int rows_ = 0;
  int cols_ = 0;
  int channels_ = 0;
  bool empty_ = true;
};
}  // namespace pixelator
