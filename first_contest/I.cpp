#include <iostream>

int64_t Max(int64_t w, int64_t h) {
  int64_t max;
  if (w > h) {
    max = w;
  } else {
    max = h;
  }
  return max;
}

int main() {
  int64_t w;
  int64_t h;
  int64_t amount;
  int64_t right;
  int64_t left;
  int64_t middle;
  std::cin >> w >> h >> amount;
  right = Max(w, h) * amount;
  left = Max(w, h);
  for (int64_t i = 0; right - left > 0; ++i) {
    middle = (right + left) / 2;
    (amount > (middle / w) * (middle / h)) ? left = middle + 1 : right = middle;
  }
  std::cout << left;
  return 0;
}
