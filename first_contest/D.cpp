#include <iostream>

int LenArrey(int quantity) {
  int len = 0;
  for (int i = 1; i <= quantity; ++i) {
    len = (len * 2) + 1;
  }
  return len;
}

void Clean(int quantity, int* clean, int len) {
  if (quantity == 1) {
    clean[len - 1] = -1;
    return;
  }
  Clean(quantity - 1, clean, len);
  clean[len - 1 - LenArrey(quantity - 1)] = (-1) * quantity;
  for (int i = len - 1; i > len - 1 - LenArrey(quantity - 1); --i) {
    clean[2 * (len - 1 - LenArrey(quantity - 1)) - i] = (-1) * clean[i];
  }
}

void Steps(int n, int* clean, int len) {
  int chip_one;
  int chip_two;
  for (int i = 1; i <= n; ++i) {
    if (i == 1) {
      std::cout << 1 << " ";
    } else if (i == 2) {
      chip_one = 1;
      chip_two = 2;
      std::cout << 2 << " ";
    } else {
      chip_one = chip_two;
      chip_two = chip_one + 1;
      Clean(i - 2, clean, LenArrey(i - 2));
      for (int j = 0; j < LenArrey(i - 2); ++j) {
        std::cout << clean[j] << " ";
      }
      std::cout << chip_two << " ";
    }
  }
  if (n - 2 > 0) {
    Steps(n - 2, clean, len);
  }
}

int main() {
  int quantity;
  int len;
  std::cin >> quantity;
  len = LenArrey(quantity - 2);
  auto* clean = new int[len];
  Steps(quantity, clean, len);
  delete[] clean;
  return 0;
}
