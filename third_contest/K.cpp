#include <iostream>

void Solution(int n, int* arr_one, int m, int* arr_two) {
  int dp[1001][1001] = {0};
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      if (arr_one[i - 1] == arr_two[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int len_answer = 0;
  int answer[1001] = {0};
  while (n > 0 && m > 0) {
    if (arr_one[n - 1] == arr_two[m - 1]) {
      answer[len_answer] = arr_one[n - 1];
      --n;
      --m;
      ++len_answer;
    } else if (dp[n - 1][m] == dp[n][m]) {
      --n;
    } else {
      --m;
    }
  }
  for (int i = len_answer - 1; i >= 0; --i) {
    std::cout << answer[i] << " ";
  }
}

int main() {
  int n;
  std::cin >> n;
  auto* arr_one = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr_one[i];
  }
  int m;
  std::cin >> m;
  auto* arr_two = new int[m];
  for (int i = 0; i < m; ++i) {
    std::cin >> arr_two[i];
  }
  Solution(n, arr_one, m, arr_two);
  delete[] arr_one;
  delete[] arr_two;
  return 0;
}
