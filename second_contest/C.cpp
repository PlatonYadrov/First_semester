#include <iostream>

int64_t Max(int64_t var_one, int64_t var_two) {
  if (var_one > var_two) {
    return var_one;
  }
  return var_two;
}

int main() {
  int64_t height = 0;
  int amount;
  std::cin >> amount;
  for (int i = 0; i < amount; ++i) {
    int var_one;
    int var_two;
    std::cin >> var_one >> var_two;
    height += Max(var_one, var_two);
  }
  std::cout << height;
  return 0;
}
