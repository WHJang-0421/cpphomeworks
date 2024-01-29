#pragma once
#include "ftxui/screen/screen.hpp"
#include "pixelator/image.hpp"
#include <string>

namespace pixelator {
class Drawer {
 public:
  Drawer(ftxui::Dimensions dimension);
  int rows() const;
  int cols() const;
  Size size() const;
  void Set(Image image);
  void Draw() const;
  std::string ToString() const;

 private:
  ftxui::Screen screen;
  static ftxui::Dimensions modifyDim(ftxui::Dimensions input_dim);
};
}  // namespace pixelator
