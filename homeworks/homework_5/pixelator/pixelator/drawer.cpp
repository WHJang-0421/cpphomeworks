#include "pixelator/drawer.hpp"

namespace pixelator {
ftxui::Dimensions Drawer::modifyDim(ftxui::Dimensions input_dim) {
  if (input_dim.dimx == ftxui::Dimension::Full().dimx &&
      input_dim.dimy == ftxui::Dimension::Full().dimy)
    return input_dim;
  return {input_dim.dimx, input_dim.dimx};
}
Drawer::Drawer(ftxui::Dimensions dimension)
    : screen(ftxui::Screen::Create(modifyDim(dimension))) {}

int Drawer::rows() const { return screen.dimy(); }
int Drawer::cols() const { return 2 * screen.dimx(); }
Size Drawer::size() const { return {rows(), cols()}; }
void Drawer::Set(Image image) {
  for (int i = 0; i < image.rows(); ++i) {
    if (i < rows()) {
      for (int j = 0; j < image.cols(); ++j) {
        if (2 * j < cols()) {
          screen.PixelAt(2 * j, i).background_color = image.at(i, j);
        }
        if (2 * j + 1 < cols()) {
          screen.PixelAt(2 * j + 1, i).background_color = image.at(i, j);
        }
      }
    }
  }
}
void Drawer::Draw() const { screen.Print(); }
std::string Drawer::ToString() const { return screen.ToString(); }

}  // namespace pixelator
