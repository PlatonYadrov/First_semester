#include "string_view.h"
#include <cstring>

StringView::StringView() : string_(nullptr) {
}

StringView::StringView(const char* string) : string_(string), size_(strlen(string_)) {
}

StringView::StringView(const char* string, size_t size) : string_(string), size_(size) {
}

const char& StringView::operator[](size_t index) const {
  return *(string_ + index);
}

const char& StringView::At(size_t index) const {
  if (index >= size_) {
    throw StringViewOutOfRange{};
  }
  return *(string_ + index);
}

const char& StringView::Front() const {
  return *string_;
}

const char& StringView::Back() const {
  return *(string_ + size_ - 1);
}

size_t StringView::Size() const {
  return size_;
}

size_t StringView::Length() const {
  return size_;
}

bool StringView::Empty() const {
  return size_ == 0;
}

const char* StringView::Data() const {
  return string_;
}

void StringView::Swap(StringView& other) {
  auto temp_str = other.string_;
  other.string_ = string_;
  string_ = temp_str;
  auto temp_size = other.size_;
  other.size_ = size_;
  size_ = temp_size;
}

void StringView::RemovePrefix(size_t prefix_size) {
  for (size_t i = 0; i < prefix_size; ++i) {
    ++string_;
    --size_;
  }
}

void StringView::RemoveSuffix(size_t suffix_size) {
  for (size_t i = 0; i < suffix_size; ++i) {
    --size_;
  }
}

StringView StringView::Substr(size_t pos, size_t count = -1) {
  size_t len;
  if (Size() - pos <= 0) {
    throw StringViewOutOfRange{};
  }
  if (Size() - pos < count) {
    len = Size() - pos;
  } else {
    len = count;
  }
  auto str = string_ + pos;
  StringView string(str, len);
  return string;
}
