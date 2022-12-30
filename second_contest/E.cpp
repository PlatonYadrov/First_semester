#include <iostream>

int64_t PushHeap(int64_t* begin, int64_t size) {
  int64_t index = size;
  while (*(begin + index) > *(begin + (index - 1) / 2)) {
    int64_t temp = *(begin + index);
    *(begin + index) = *(begin + (index - 1) / 2);
    *(begin + (index - 1) / 2) = temp;
    index = (index - 1) / 2;
  }
  return index;
}

int64_t PopHeap(int64_t* begin, int64_t size) {
  int64_t temp = *(begin);
  *(begin) = *(begin + size - 1);
  *(begin + size - 1) = temp;
  int64_t max = 0;
  int64_t left;
  int64_t right;
  int64_t max_old;
  while (2 * max + 1 < size - 1) {
    left = 2 * max + 1;
    right = 2 * max + 2;
    max_old = left;
    if ((right < size - 1) && (*(begin + right) > *(begin + left))) {
      max_old = right;
    }
    if (*(begin + max) >= *(begin + max_old)) {
      return max;
    }
    int64_t temp_local = *(begin + max);
    *(begin + max) = *(begin + max_old);
    *(begin + max_old) = temp_local;
    max = max_old;
  }
  return max;
}

int64_t PopAny(int64_t* begin, int64_t plase, int64_t size) {
  int64_t temp = *(begin + plase);
  *(begin + plase) = *(begin + size - 1);
  *(begin + size - 1) = temp;
  int64_t max = plase;
  int64_t left;
  int64_t right;
  int64_t max_old;
  while (2 * max + 1 < size - 1) {
    left = 2 * max + 1;
    right = 2 * max + 2;
    max_old = left;
    if ((right < size - 1) && (*(begin + right) > *(begin + left))) {
      max_old = right;
    }
    if (*(begin + max) >= *(begin + max_old)) {
      break;
    }
    int64_t temp_local = *(begin + max);
    *(begin + max) = *(begin + max_old);
    *(begin + max_old) = temp_local;
    max = max_old;
  }
  max = plase;
  while (*(begin + max) > *(begin + (max - 1) / 2)) {
    int64_t temp_more = *(begin + (max - 1) / 2);
    *(begin + (max - 1) / 2) = *(begin + max);
    *(begin + max) = temp_more;
    max = (max - 1) / 2;
  }
  return temp;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int64_t n;
  int64_t m;
  int64_t size = 0;
  int64_t command;
  std::cin >> n >> m;
  auto* arr = new int64_t[n + 100];
  for (int64_t i = 0; i < m; ++i) {
    std::cin >> command;
    if (command == 1) {
      if (size < 1) {
        std::cout << -1 << '\n';
      } else if (size == 1) {
        std::cout << 0 << " " << arr[0] << '\n';
        --size;
      } else {
        int64_t first_arr = arr[0];
        std::cout << PopHeap(arr, size) + 1 << " " << first_arr << '\n';
        --size;
      }
    }
    if (command == 2) {
      if (size == n) {
        int64_t okey;
        std::cin >> okey;
        std::cout << -1 << '\n';
      } else {
        std::cin >> arr[size];
        std::cout << PushHeap(arr, size) + 1 << '\n';
        ++size;
      }
    }
    if (command == 3) {
      int64_t plase;
      std::cin >> plase;
      if (plase - 1 >= size || size == 0 || plase < 1) {
        std::cout << -1 << '\n';
      } else {
        std::cout << PopAny(arr, plase - 1, size) << '\n';
        --size;
      }
    }
  }
  for (int64_t j = 0; j < size; ++j) {
    std::cout << arr[j] << " ";
  }
  delete[] arr;
}
