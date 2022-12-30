#include <iostream>

int Solution(int i, int k, char *str) {
  int left;
  int right;
  int64_t local_count;
  int64_t count = 0;
  for (int j = 1; j < i - k + 1;) {
    right = j + k;
    if (str[j] == str[right]) {
      left = j;
      local_count = 0;
      while ((right < i) && (str[left] == str[right])) {
        local_count += 1;
        left += 1;
        right += 1;
      }
      if (local_count == 1) {
        count += 1;
      } else {
        count += ((1 + local_count) * local_count) / 2;
      }
      j += local_count + 1;
    } else {
      j += 1;
    }
  }
  return count;
}

int main() {
  int size;
  int k;
  char str[1000100];
  std::cin >> k;
  int indicator = 0;
  for (size = 0; true; ++size) {
    str[size] = getchar();
    if (str[size] == '\n' || str[size] == '\0') {
      indicator += 1;
      if (indicator == 2) {
        break;
      }
    }
  }
  str[size] = '?';
  str[size + 1] = '\0';
  std::cout << Solution(size, k, str);
  return 0;
}
