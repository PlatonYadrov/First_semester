#include <iostream>

bool Fight(int *positions, int len) {
  bool fight = true;
  for (int i = 0; i < len; ++i) {
    bool check_one = (positions[i] == positions[len]);
    bool check_two = (i - len == positions[i] - positions[len]) || (len - i == positions[i] - positions[len]);
    bool check = check_one || check_two;
    check ? fight = false : fight = true;
    if (!fight) {
      break;
    }
  }
  return fight;
}

int Queens(int *positions, int amount, int len) {
  int count = 0;
  for (int j = 0; j < amount; ++j) {
    positions[len] = j;
    if (Fight(positions, len)) {
      if (len >= amount - 1) {
        count += 1;
      } else {
        count += Queens(positions, amount, len + 1);
      }
    }
  }
  return count;
}

int main() {
  int amount;
  std::cin >> amount;
  auto *positions = new int[amount];
  std::cout << Queens(positions, amount, 0);
  delete[] positions;
  return 0;
}
