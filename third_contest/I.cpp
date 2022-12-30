#include <iostream>

void Solution(int n) {
  auto dp = new int[n + 1];
  dp[1] = 0;
  for (int i = 2; i < n + 1; ++i) {
    if (i % 6 == 0) {
      dp[i] = std::min(dp[i / 2], dp[i - 1]);
      dp[i] = std::min(dp[i], dp[i / 3]) + 1;
    } else if (i % 3 == 0) {
      dp[i] = std::min(dp[i / 3], dp[i - 1]) + 1;
    } else if (i % 2 == 0) {
      dp[i] = std::min(dp[i / 2], dp[i - 1]) + 1;
    } else {
      dp[i] = dp[i - 1] + 1;
    }
  }
  std::cout << dp[n];
  delete[] dp;
}

int main() {
  int n;
  std::cin >> n;
  Solution(n);
  return 0;
}
