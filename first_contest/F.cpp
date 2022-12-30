#include <iostream>

void MovingHanoi(int all, const int kernel_one, const int kernel_last) {
  if (all == 0) {
    return;
  }
  if (all != 0) {
    int tmporary;
    tmporary = 6 - kernel_one;
    tmporary -= kernel_last;
    MovingHanoi(all - 1, kernel_one, tmporary);
    std::cout << all << " " << kernel_one << " " << kernel_last << "\n";
    MovingHanoi(all - 1, tmporary, kernel_last);
    return;
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
