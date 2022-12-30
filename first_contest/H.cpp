#include <iostream>

int main() {
  int size = 100010;
  int length;
  auto* cipher = new char[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> cipher[i];
    if (cipher[i] == '#') {
      length = i;
      break;
    }
  }
  if (length % 2 == 1) {
    for (int i = 0; i < length; i += 2) {
      std::cout << cipher[i];
    }
    for (int i = length - 2; i > 0; i -= 2) {
      std::cout << cipher[i];
    }
  } else {
    for (int i = 0; i < length; i += 2) {
      std::cout << cipher[i];
    }
    for (int i = length - 1; i > 0; i -= 2) {
      std::cout << cipher[i];
    }
  }
  delete[] cipher;
  return 0;
}
