#include <iostream>

void Bin(int* arr, int len_arr) {
  int left = 0;
  int len_arr_now = len_arr;
  int right = 0;
  int count = 0;
  auto* help_one = new int[3000];
  auto* help_two = new int[len_arr + 1];
  while (len_arr != 1 || arr[0] != 1) {
    help_one[count] = arr[len_arr - 1] % 2;
    ++count;
    int local_count = len_arr - 1;
    while (local_count >= 0) {
      left = arr[local_count] * 5 + right;
      right = left / 10;
      if (arr[0] == 1) {
        help_two[local_count + len_arr_now - len_arr] = left % 10;
      } else {
        help_two[local_count + len_arr_now - len_arr + 1] = left % 10;
      }
      --local_count;
    }
    if (right != 0) {
      help_two[0] = right;
    }
    if (arr[0] != 1) {
      help_two[len_arr_now] = '\0';
      for (int i = 0; i < len_arr_now + 1; ++i) {
        arr[i] = help_two[i];
      }
    } else {
      help_two[len_arr_now - 1] = '\0';
      for (int i = 0; i < len_arr_now; ++i) {
        arr[i] = help_two[i];
      }
      --len_arr_now;
    }
    len_arr = len_arr_now;
    right = 0;
    left = 0;
  }
  std::cout << 1;
  while (count - 1 >= 0) {
    std::cout << help_one[count - 1];
    --count;
  }
  delete[] help_two;
  delete[] help_one;
}

int main() {
  int len_arr_now;
  int arr[260];
  for (int i = 0; i < 260; ++i) {
    arr[i] = -1;
  }
  int len_str;
  char str[260];
  for (len_str = 0; true; ++len_str) {
    str[len_str] = getchar();
    if (str[len_str] == '\n' || str[len_str] == '\0') {
      break;
    }
  }
  str[len_str] = '\0';
  for (int j = 0; j < len_str; ++j) {
    if (str[j] >= '1' and str[j] <= '9') {
      len_arr_now = 0;
      while (str[j] >= '0' and str[j] <= '9') {
        arr[len_arr_now] = (static_cast<int>(str[j]) - '0');
        ++len_arr_now;
        ++j;
      }
      Bin(arr, len_arr_now);
      for (int k = 0; k < len_arr_now; ++k) {
        arr[k] = -1;
      }
    }
    if (str[j] != '\0') {
      std::cout << str[j];
    }
  }
  return 0;
}
