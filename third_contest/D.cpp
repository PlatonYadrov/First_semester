#include <iostream>

int64_t Solution(int n, int64_t* dp) {
  if (n == 1) {
    return 3;
  }
  if (n == 2) {
    return 8;
  }
  if (dp[n] == 0) {
    dp[n] = 2 * (Solution(n - 1, dp) + Solution(n - 2, dp));
  }
  return dp[n];
}

int main() {
  int n;
  int64_t dp[100] = {0};
  std::cin >> n;
  std::cout << Solution(n, dp);
  return 0;
}
