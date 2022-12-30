#include <iostream>

int64_t Solution(int n) {
  int64_t numbers = 0;
  int64_t dp[10][100] = {0};
  for (int i = 0; i < 10; ++i) {
    dp[i][1] = 1;
  }
  for (int i = 0; i < 10; ++i) {
    if (i == 4 || i == 6) {
      dp[i][2] = 3;
      continue;
    }
    if (i == 5) {
      dp[i][2] = 0;
      continue;
    }
    dp[i][2] = 2;
  }
  for (int i = 3; i < n + 1; ++i) {
    dp[0][i] = dp[4][i - 1] + dp[6][i - 1];
    dp[1][i] = dp[6][i - 1] + dp[8][i - 1];
    dp[2][i] = dp[7][i - 1] + dp[9][i - 1];
    dp[3][i] = dp[4][i - 1] + dp[8][i - 1];
    dp[4][i] = dp[0][i - 1] + dp[3][i - 1] + dp[9][i - 1];
    dp[6][i] = dp[0][i - 1] + dp[1][i - 1] + dp[7][i - 1];
    dp[7][i] = dp[2][i - 1] + dp[6][i - 1];
    dp[8][i] = dp[1][i - 1] + dp[3][i - 1];
    dp[9][i] = dp[2][i - 1] + dp[4][i - 1];
  }
  for (int i = 1; i < 10; ++i) {
    if (i == 8) {
      continue;
    }
    numbers += dp[i][n];
  }
  return numbers;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << Solution(n);
  return 0;
}
