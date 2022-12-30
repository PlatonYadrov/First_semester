#include <iostream>

int64_t Solution(int m, int n) {
  int64_t dp[51][51];
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i < n - 1 && j < m - 1) {
        dp[i + 1][j + 1] += dp[i][j];
      }
      if (i < n - 1) {
        dp[i + 1][j] += dp[i][j];
      }
      if (j < m - 1) {
        dp[i][j + 1] += dp[i][j];
      }
    }
  }
  return dp[n - 1][m - 1];
}

int main() {
  int m;
  int n;
  std::cin >> m >> n;
  std::cout << Solution(m, n);
  return 0;
}
