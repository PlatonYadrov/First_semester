#include <iostream>

int len_coints_new = 30;

inline void Solve(int amount, int prise, int len_coints, int all_coints, int *answer, int *coints, int *my_coints) {
  if ((all_coints >= len_coints_new) || (prise < 0)) {
    return;
  }
  if (prise == 0) {
    if (all_coints <= len_coints_new) {
      len_coints_new = all_coints;
      for (int i = 0; i < len_coints_new; ++i) {
        answer[i] = my_coints[i];
      }
    }
  } else {
    for (int i = len_coints; i < amount * 2; ++i) {
      if (i != 0) {
        if (coints[i] == coints[i - 1] && i != len_coints) {
          continue;
        }
      }
      my_coints[all_coints] = coints[i];
      Solve(amount, prise - my_coints[all_coints], i + 1, all_coints + 1, answer, coints, my_coints);
    }
  }
}

int main() {
  int amount;
  int prise;
  int sum = 0;
  std::cin >> prise >> amount;
  int coints[30];
  int answer[30];
  int my_coints[30];
  for (int i = 0; i < amount * 2; i += 2) {
    std::cin >> coints[i];
    sum += coints[i];
    coints[i + 1] = coints[i];
  }
  if (sum * 2 < prise) {
    std::cout << -1;
    return 0;
  }
  Solve(amount, prise, 0, 0, answer, coints, my_coints);
  if (len_coints_new == 30) {
    std::cout << 0;
    return 0;
  }
  std::cout << len_coints_new << "\n";
  for (int i = 0; i < len_coints_new; ++i) {
    std::cout << answer[i] << " ";
  }
  return 0;
}
