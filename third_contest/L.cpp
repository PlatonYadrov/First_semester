#include <iostream>

void Solution(int n, int* arr) {
  auto prev = new int[n];
  auto dp = new int[n];
  for (int i = 0; i < n; ++i) {
    dp[i] = 1;
    prev[i] = -1;
    for (int j = 0; j <= i - 1; ++j) {
      if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        prev[i] = j;
      }
    }
  }
  int pos = 0;
  int lenght = dp[0];
  for (int i = 0; i < n; ++i) {
    if (dp[i] > lenght) {
      pos = i;
      lenght = dp[i];
    }
  }
  auto answer = new int[n];
  int i;
  for (i = 0; pos != -1; ++i) {
    answer[i] = arr[pos];
    pos = prev[pos];
  }
  for (int j = i - 1; j >= 0; --j) {
    std::cout << answer[j] << " ";
  }
  delete[] prev;
  delete[] dp;
  delete[] answer;
}

int main() {
  int n;
  std::cin >> n;
  auto* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  Solution(n, arr);
  delete[] arr;
  return 0;
}
