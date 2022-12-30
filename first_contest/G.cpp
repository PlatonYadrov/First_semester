#include <iostream>

int indicator = 0;

void MovingHanoi(int all, const int kernel_one, const int kernel_last) {
  if (all == 0) {
    return;
  }
  if (all != 0) {
    int tmporary;
    tmporary = 6 - kernel_one;
    tmporary -= kernel_last;
    MovingHanoi(all - 1, kernel_one, kernel_last);
    if (all != 1) {
      std::cout << all << " " << kernel_one << " " << tmporary << "\n";
      indicator = all;
    }
    if (all == 1) {
      if (indicator != 1) {
        std::cout << all << " " << kernel_one << " " << kernel_last << "\n";
        indicator = all;
      }
    }
    MovingHanoi(all - 1, kernel_last, kernel_one);
    if (all != 1) {
      std::cout << all << " " << tmporary << " " << kernel_last << "\n";
      indicator = all;
    }
    if (all == 1) {
      if (indicator != 1) {
        std::cout << all << " " << kernel_last << " " << kernel_one << "\n";
        indicator = all;
      }
    }
    MovingHanoi(all - 1, kernel_one, kernel_last);
  }
}

int main() {
  int all;
  const int kernel_one = 1;
  const int kernel_last = 3;
  std::cin >> all;
  MovingHanoi(all, kernel_one, kernel_last);
  return 0;
}
