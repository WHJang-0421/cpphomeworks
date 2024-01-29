#include "pixelator/stb_image_data_view.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

namespace {
static constexpr auto kLoadAllChannels{0};
}

namespace pixelator {
StbImageDataView::StbImageDataView(std::filesystem::path image_path) {
  image_data_ = stbi_load(
      image_path.c_str(), &cols_, &rows_, &channels_, kLoadAllChannels);
  empty_ = false;
}
StbImageDataView::StbImageDataView() {}
StbImageDataView::StbImageDataView(StbImageDataView&& other)
    : image_data_(other.image_data_),
      rows_(other.rows_),
      cols_(other.cols_),
      channels_(other.channels_),
      empty_(other.empty_) {
  other.image_data_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
  other.channels_ = 0;
  other.empty_ = true;
}
StbImageDataView::~StbImageDataView() {
  if (image_data_ == nullptr) return;
  stbi_image_free(image_data_);
}
StbImageDataView& StbImageDataView::operator=(StbImageDataView&& other) {
  this->image_data_ = other.image_data_;
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->channels_ = other.channels_;
  this->empty_ = other.empty_;
  other.image_data_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
  other.channels_ = 0;
  other.empty_ = true;
  return *this;
}

Size StbImageDataView::size() const { return {rows(), cols()}; }
int StbImageDataView::rows() const { return rows_; }
int StbImageDataView::cols() const { return cols_; }
bool StbImageDataView::empty() const { return empty_; }
ftxui::Color StbImageDataView::at(int query_row, int query_col) const {
  const auto index = channels_ * (query_row * cols_ + query_col);
  return ftxui::Color::RGB(
      image_data_[index], image_data_[index], image_data_[index]);
}
}  // namespace pixelator
