#include <iostream>
#include <algorithm>

int Solution(int n, int* arr) {
  auto* dp = new int[n];
  dp[0] = 99999999;
  dp[1] = arr[1] - arr[0];
  if (n > 2) {
    dp[2] = arr[2] - arr[0];
  }
  for (int i = 3; i < n; ++i) {
    dp[i] = std::min(dp[i - 2] + arr[i] - arr[i - 1], dp[i - 3] + arr[i] - arr[i - 2]);
  }
  int temp = dp[n - 1];
  delete[] dp;
  return temp;
}

int main() {
  int n;
  std::cin >> n;
  auto* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  std::sort(arr, arr + n);
  std::cout << Solution(n, arr);
  delete[] arr;
  return 0;
}
