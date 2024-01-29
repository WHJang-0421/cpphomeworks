#include "pixelator/pixelate_image.hpp"

namespace {
int Scale(int number, float factor) {
  return static_cast<int>(number * factor);
}
}  // namespace

namespace pixelator {
Image PixelateImage(const StbImageDataView& original_image, Size new_size) {
  const auto factor_cols =
      new_size.cols / static_cast<float>(original_image.cols());
  const auto factor_rows =
      new_size.rows / static_cast<float>(original_image.rows());
  const auto factor = std::min(std::min(factor_cols, factor_rows), 1.0f);

  Image new_image{Scale(original_image.rows(), factor),
                  Scale(original_image.rows(), factor)};
  for (int i = 0; i < new_image.rows(); ++i) {
    for (int j = 0; j < new_image.cols(); ++j) {
      int sample_row = Scale(i, 1 / factor);
      int sample_col = Scale(j, 1 / factor);

      if (sample_row < original_image.rows() &&
          sample_col < original_image.cols()) {
        new_image.at(i, j) =
            original_image.at(Scale(i, 1 / factor), Scale(j, 1 / factor));
      }
    }
  }
  return new_image;
}
}  // namespace pixelator
