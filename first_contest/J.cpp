#include <iostream>

void Solution(char *clean_str, int len) {
  char new_clean_str[100100];
  char new_new_clean_str[100100];
  for (int j = 0; j < len; ++j) {
    new_clean_str[j] = clean_str[j];
    new_new_clean_str[j] = clean_str[j];
  }
  int inconsistencies = 0;
  int indicator = 0;
  for (int j = 0; j <= (len / 2 - (len + 1) % 2); ++j) {
    if (clean_str[j] != clean_str[len - 1 - j]) {
      inconsistencies += 1;
      if (inconsistencies == 1) {
        indicator = j;
      }
      clean_str[j] = clean_str[len - 1 - j];
      if (inconsistencies >= 2) {
        break;
      }
    }
  }
  if (inconsistencies != 2) {
    std::cout << "YES";
    std::cout << "\n";
    std::cout << clean_str;
    return;
  }
  for (int j = 0; j < len; ++j) {
    if (j > indicator) {
      new_clean_str[j - 1] = new_clean_str[j];
    }
  }
  int another_indicator = 0;
  for (int j = 0; j <= ((len - 1) / 2 - len % 2); ++j) {
    if (new_clean_str[j] != new_clean_str[len - 2 - j]) {
      another_indicator += 1;
      break;
    }
  }
  if (another_indicator != 1) {
    std::cout << "YES";
    std::cout << "\n";
    for (int j = 0; j < len - 1; ++j) {
      std::cout << new_clean_str[j];
    }
    return;
  }
  for (int j = len - 1; j > -1; --j) {
    if (j != indicator) {
      new_new_clean_str[j + 1] = new_new_clean_str[j];
    } else {
      new_new_clean_str[j + 1] = new_new_clean_str[j];
      new_new_clean_str[indicator] = new_new_clean_str[len - indicator];
      break;
    }
  }
  for (int j = 0; j <= ((len + 1) / 2 - len % 2); ++j) {
    if (new_new_clean_str[j] != new_new_clean_str[len - j]) {
      another_indicator += 1;
      break;
    }
  }
  if (another_indicator != 2) {
    std::cout << "YES";
    std::cout << "\n";
    std::cout << new_new_clean_str;
    return;
  }
  std::cout << "NO";
}

int main() {
  int i;
  char str[100100];
  char clean_str[100100];
  int len = 0;
  for (i = 0; true; ++i) {
    str[i] = getchar();
    if (str[i] == '\n' || str[i] == '\0') {
      break;
    }
  }
  str[i] = '\0';
  for (int j = 0; j < i; ++j) {
    if (((str[j] >= 'A') && (str[j] <= 'Z')) || ((str[j] >= 'a') && (str[j] <= 'z'))) {
      if ((str[j] >= 'a') && (str[j] <= 'z')) {
        clean_str[len] = str[j] - ('a' - 'A');
        len += 1;
      } else {
        clean_str[len] = str[j];
        len += 1;
      }
    }
  }
  Solution(clean_str, len);
}
