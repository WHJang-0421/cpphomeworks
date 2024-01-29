#pragma once
#include "pixelator/image.hpp"

namespace pixelator {
Image PixelateImage(const StbImageDataView& original_image, Size new_size);
}
