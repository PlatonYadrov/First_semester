#include <iostream>

int64_t Pow(int64_t n) {
  return (1 << n);
}

int64_t Find(int64_t mask, int64_t k) {
  return (mask & Pow(k)) > 0;
}

int64_t Solution(int64_t n, int64_t m) {
  int64_t mask_ok = 0;
  auto** dp = new int64_t*[m + 2];
  for (int64_t i = 0; i <= m + 1; ++i) {
    dp[i] = new int64_t[Pow(n)];
  }
  for (int64_t i = 0; i <= m + 1; ++i) {
    for (int64_t j = 0; j < Pow(n); ++j) {
      dp[i][j] = 0;
    }
  }
  for (int64_t i = 0; i < n; i += 2) {
    mask_ok |= Pow(i);
  }
  dp[0][mask_ok] = 1;
  for (int64_t i = 0; i < m + 1; ++i) {
    for (int64_t left_mask = 0; left_mask < Pow(n); ++left_mask) {
      for (int64_t right_mask = 0; right_mask < Pow(n); ++right_mask) {
        int flag = 1;
        for (int64_t j = 0; j < n - 1; ++j) {
          if ((Find(left_mask, j) == Find(left_mask, j + 1)) && (Find(right_mask, j) == Find(right_mask, j + 1)) &&
              (Find(left_mask, j) == Find(right_mask, j))) {
            flag = 0;
          }
        }
        if (flag == 1) {
          dp[i + 1][right_mask] += dp[i][left_mask];
        }
      }
    }
  }
  std::cout << dp[m + 1][mask_ok];
  for (int64_t i = 0; i <= m + 1; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
  return 0;
}

int main() {
  int64_t n;
  int64_t m;
  std::cin >> n >> m;
  if (n > m) {
    int64_t temp = n;
    n = m;
    m = temp;
  }
  if (n == 1) {
    std::cout << Pow(m);
    return 0;
  }
  Solution(n, m);
  return 0;
}
