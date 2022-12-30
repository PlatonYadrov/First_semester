#include <iostream>

int64_t Solution(int64_t n, int64_t* arr, int64_t* numbers) {
  int64_t count = 0;
  for (int64_t i = 0; i < n; ++i) {
    for (int j = 0; j < arr[i]; ++j) {
      numbers[arr[i]] += numbers[j];
    }
    numbers[arr[i]] += 1;
    numbers[arr[i]] %= 1000000;
  }
  for (int64_t i = 0; i < 5010; ++i) {
    count += numbers[i];
  }
  return count;
}

int main() {
  int64_t n;
  std::cin >> n;
  int64_t numbers[5010] = {0};
  auto* arr = new int64_t[n];
  for (int64_t i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  int64_t answer = Solution(n, arr, numbers);
  std::cout << answer % 1000000;
  delete[] arr;
  return 0;
}
