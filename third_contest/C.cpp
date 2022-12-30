#include <iostream>

int64_t Fib(int n, int64_t* dp) {
  if (n == 1) {
    return 2;
  }
  if (n == 2) {
    return 3;
  }
  if (dp[n] == 0) {
    dp[n] = Fib(n - 1, dp) + Fib(n - 2, dp);
  }
  return dp[n];
}

int main() {
  int n;
  int64_t dp[100] = {0};
  std::cin >> n;
  std::cout << Fib(n, dp);
  return 0;
}
