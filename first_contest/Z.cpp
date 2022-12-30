#include <iostream>

void Swap(int64_t& a, int64_t& b) {
  int temp = b;
  b = a;
  a = temp;
}

void Solution(int64_t height, int64_t lenght, int64_t amount) {
  auto* cells = new int64_t[amount];
  for (int64_t i = 0; i < amount; ++i) {
    cells[i] = 0;
  }
  if (height > lenght) {
    Swap(height, lenght);
  }
  while (height > 0 && lenght > 0 && lenght > amount) {
    int64_t div = lenght / amount;
    lenght %= amount;
    for (int64_t i = 0; i < amount; ++i) {
      cells[i] += div * height;
    }
    if (height > lenght) {
      Swap(lenght, height);
    }
  }
  if (height == 0) {
    for (int64_t i = 0; i < amount; ++i) {
      std::cout << cells[i] << " ";
    }
    delete[] cells;
    return;
  }
  for (int64_t i = 0; i < lenght; ++i) {
    if (i < height) {
      cells[i] += i + 1 - 1 + 1;
    } else {
      cells[i] += height;
    }
  }
  for (int64_t i = 1; i < height; ++i) {
    cells[(lenght - 1 + i) % amount] += height - i;
  }
  for (int64_t i = 0; i < amount; ++i) {
    std::cout << cells[i] << " ";
  }
  delete[] cells;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int64_t lenght;
  int64_t height;
  int64_t amount;
  std::cin >> height >> lenght >> amount;
  Solution(height, lenght, amount);
  return 0;
}
