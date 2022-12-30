#include <iostream>

void Solution(int m, int n, int* weight, int* price) {
  auto** dp = new int*[n + 1];
  for (int i = 0; i < n + 1; ++i) {
    dp[i] = new int[m + 1];
  }
  for (int i = 0; i < n + 1; ++i) {
    for (int j = 0; j < m + 1; ++j) {
      dp[i][j] = 0;
    }
  }
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      if (j >= weight[i]) {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + price[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  int ans[101];
  int len_ans = 0;
  for (int i = n; i > 0; --i) {
    if (dp[i][m] != dp[i - 1][m]) {
      ans[len_ans] = i;
      m -= weight[i];
      ++len_ans;
    }
  }
  for (int i = len_ans - 1; i >= 0; --i) {
    std::cout << ans[i] << '\n';
  }
  for (int i = 0; i < n + 1; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
}

int main() {
  int n;
  int m;
  std::cin >> n >> m;
  auto* weight = new int[n + 1];
  for (int i = 1; i < n + 1; ++i) {
    std::cin >> weight[i];
  }
  auto* price = new int[n + 1];
  for (int i = 1; i < n + 1; ++i) {
    std::cin >> price[i];
  }
  Solution(m, n, weight, price);
  delete[] weight;
  delete[] price;
  return 0;
}
