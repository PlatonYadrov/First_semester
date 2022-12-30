#include <iostream>
#include <cstring>
int Distan(const char* first_str, const char* second_str, int delete_cost, int insert_cost, int repl_cost) {
  int len_first = strlen(first_str);
  int len_second = strlen(second_str);
  auto dp = new int*[len_first + 1];
  for (int i = 0; i < len_first + 1; ++i) {
    dp[i] = new int[len_second + 1];
  }
  for (int i = 0; i < len_first + 1; ++i) {
    dp[i][0] = i * delete_cost;
  }
  for (int i = 0; i < len_second + 1; ++i) {
    dp[0][i] = i * insert_cost;
  }
  for (int i = 1; i < len_first + 1; ++i) {
    for (int j = 1; j < len_second + 1; ++j) {
      if (first_str[i - 1] == second_str[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = dp[i][j - 1] + insert_cost;
        dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + delete_cost);
        dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + repl_cost);
      }
    }
  }
  int res = dp[len_first][len_second];
  for (int i = 0; i < len_first + 1; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
  return res;
}

int main() {
  auto first_str = new char[5000];
  auto second_str = new char[5000];
  std::cin >> first_str >> second_str;
  std::cout << Distan(first_str, second_str, 1, 1, 1);
  delete[] first_str;
  delete[] second_str;
}
