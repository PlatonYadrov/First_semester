#include <iostream>
#include <algorithm>

int64_t Solution(int64_t k, int64_t n, int64_t* cards) {
  int64_t count = 0;
  int64_t pair[200003];
  int64_t len_pair = 0;
  for (int64_t i = 0; i < n;) {
    int64_t count = 0;
    while ((i + 1 < n) && (cards[i] == cards[i + 1])) {
      ++count;
      ++i;
    }
    ++count;
    ++i;
    pair[len_pair] = cards[i - 1];
    pair[len_pair + 1] = count;
    len_pair += 2;
  }
  for (int64_t j = 1; j < len_pair; j += 2) {
    if (pair[j] >= 3) {
      ++count;
    }
  }
  int64_t j = 0;
  for (int64_t i = 0; i < len_pair / 2; ++i) {
    while ((j < i) && (pair[j * 2] * k < pair[i * 2])) {
      ++j;
    }
    count += 3 * (i - j) * (i - j - 1);
  }
  j = 0;
  for (int64_t i = 1; i < len_pair / 2; ++i) {
    while ((2 * i < len_pair) && (2 * j < len_pair) && (j < i) && (pair[j * 2] * k < pair[i * 2])) {
      ++j;
    }
    if ((2 * i + 1 < len_pair) && (pair[2 * i + 1] > 1)) {
      count += 3 * (i - j);
    }
  }
  j = len_pair / 2 - 1;
  for (int64_t i = len_pair / 2 - 2; i >= 0; --i) {
    while ((2 * i < len_pair) && (2 * j < len_pair) && (j > i) && (pair[j * 2] > pair[i * 2] * k)) {
      --j;
    }
    if ((2 * i + 1 < len_pair) && (pair[2 * i + 1] > 1)) {
      count += 3 * (j - i);
    }
  }
  return count;
}

int main() {
  int64_t n;
  int64_t k;
  std::cin >> n >> k;
  auto* cards = new int64_t[n];
  for (int64_t i = 0; i < n; i++) {
    std::cin >> cards[i];
  }
  std::sort(cards, cards + n);
  std::cout << Solution(k, n, cards);
  delete[] cards;
  return 0;
}
