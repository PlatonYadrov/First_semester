#include <iostream>
#include <cstring>

void Solution(int n, char* arr_one, int m, char* arr_two) {
  int len = n;
  auto dp = new int*[n + 1];
  for (int i = 0; i < n + 1; ++i) {
    dp[i] = new int[n + 1];
  }
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
  while (n > 0 && m > 0) {
    if (arr_one[n - 1] == arr_two[m - 1]) {
      --n;
      --m;
      ++len_answer;
    } else if (dp[n - 1][m] == dp[n][m]) {
      --n;
    } else {
      --m;
    }
  }
  std::cout << len - len_answer;
  for (int i = 0; i < len + 1; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
}

void LenPalindrom(char* str) {
  int len = strlen(str);
  auto reversed_str = new char[len];
  for (int i = 0; i < len; ++i) {
    reversed_str[i] = str[len - i - 1];
  }
  Solution(len, reversed_str, len, str);
  delete[] reversed_str;
}

int main() {
  auto first_str = new char[10000];
  std::cin >> first_str;
  LenPalindrom(first_str);
  delete[] first_str;
}
