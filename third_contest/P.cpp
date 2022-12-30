#include <iostream>

int Solution(int n, int* arr) {
  const int k_inf = 999999999;
  auto dp = new int[n + 1];
  dp[0] = -k_inf;
  for (int i = 1; i < n + 1; ++i) {
    dp[i] = k_inf;
  }
  for (int i = 0; i < n; ++i) {
    int left = 0;
    int right = n;
    int middle;
    while (right - left > 1) {
      middle = (left + right) / 2;
      if (dp[middle] >= arr[i]) {
        right = middle;
      } else {
        left = middle;
      }
    }
    dp[right] = arr[i];
  }
  int i = 0;
  for (i = 0; i < n + 1 && dp[i] != k_inf;) {
    ++i;
  }
  delete[] dp;
  return i;
}

int main() {
  int n;
  std::cin >> n;
  auto* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  std::cout << Solution(n, arr) - 1;
  delete[] arr;
  return 0;
}
