#include <iostream>

int Solution(int** dp, int* arr, int left, int right) {
  const int k_inf = 999999999;
  if (dp[left][right] == -1) {
    if (left - right == -1) {
      dp[left][right] = 0;
    } else {
      dp[left][right] = k_inf;
      for (int i = left + 1; i < right; ++i) {
        int var_one = dp[left][right];
        int var_two = arr[left] * arr[i] * arr[right];
        int var_three = Solution(dp, arr, left, i) + Solution(dp, arr, i, right);
        dp[left][right] = std::min(var_one, var_two + var_three);
      }
    }
  }
  return dp[left][right];
}

int main() {
  auto** dp = new int*[201];
  for (int i = 0; i < 201; ++i) {
    dp[i] = new int[201];
  }
  for (int i = 0; i < 201; ++i) {
    for (int j = 0; j < 201; ++j) {
      dp[i][j] = -1;
    }
  }
  int n;
  std::cin >> n;
  auto* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  std::cout << Solution(dp, arr, 0, n - 1);
  delete[] arr;
  for (int i = 0; i < 201; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
  return 0;
}
