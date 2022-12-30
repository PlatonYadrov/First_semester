#include <iostream>

void Solution(int** array, int x, int y, int max_x, int max_y) {
  int now_x = 1;
  int now_y = 1;
  int new_now_x = 0;
  int new_now_y = 0;
  int max = array[new_now_x][new_now_y];
  while (true) {
    if (now_x == new_now_x && now_y == new_now_y) {
      break;
    }
    now_x = new_now_x;
    now_y = new_now_y;
    for (int i = now_x; i < std::min(x, now_x + max_x); ++i) {
      for (int j = now_y; j < std::min(y, now_y + max_y); ++j) {
        if (max < array[i][j]) {
          max = array[i][j];
          new_now_x = i;
          new_now_y = j;
        }
      }
    }
  }
  std::cout << new_now_x << " " << new_now_y;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int x;
  int y;
  std::cin >> x >> y;
  int max_x;
  int max_y;
  std::cin >> max_x >> max_y;
  auto** array = new int*[x];
  for (int i = 0; i < x; ++i) {
    array[i] = new int[y];
  }
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      std::cin >> array[i][j];
    }
  }
  Solution(array, x, y, max_x, max_y);
  for (int i = 0; i < x; ++i) {
    delete[] array[i];
  }
  delete[] array;
  return 0;
}
