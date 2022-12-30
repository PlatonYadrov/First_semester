#include <iostream>

int Check(int arr[6][5], int numbers[10][6][5], int look) {
  int temp_arr[6][5];
  int overlap[10] = {0};
  int flag;
  for (int k = 0; k < 10; ++k) {
    if (k > look) {
      break;
    }
    flag = 1;
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 5; ++j) {
        temp_arr[i][j] = arr[i][j] * numbers[k][i][j];
      }
    }
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 5; ++j) {
        if (temp_arr[i][j] != arr[i][j]) {
          flag = 0;
        }
      }
    }
    overlap[k] = flag;
  }
  int var;
  int count = 0;
  for (int i = 0; i < 10; ++i) {
    if (overlap[i] == 1) {
      var = i;
      ++count;
    }
  }
  if (count > 1) {
    return 10;
  }
  if (count == 0) {
    return -1;
  }
  return var;
}

int main() {
  int numbers[10][6][5] = {
      {{0, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}},
      {{0, 0, 0, 0, 1}, {0, 0, 0, 1, 1}, {0, 0, 1, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}},
      {{0, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 1, 1, 1, 1}},
      {{0, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 1, 1, 1, 0}},
      {{0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}},
      {{0, 1, 1, 1, 1}, {0, 1, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}},
      {{0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}},
      {{0, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}},
      {{0, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}},
      {{0, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 1, 1, 1, 0}}};
  int number_one[6][5];
  int number_two[6][5];
  int number_three[6][5];
  int number_four[6][5];
  char bulb;
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 20; ++j) {
      std::cin >> bulb;
      if (j < 5) {
        if (bulb == '#') {
          number_one[i][j] = 1;
        } else {
          number_one[i][j] = 0;
        }
      } else if (j > 4 && j < 10) {
        if (bulb == '#') {
          number_two[i][j - 5] = 1;
        } else {
          number_two[i][j - 5] = 0;
        }
      } else if (j > 9 && j < 15) {
        if (bulb == '#') {
          number_three[i][j - 10] = 1;
        } else {
          number_three[i][j - 10] = 0;
        }
      } else {
        if (bulb == '#') {
          number_four[i][j - 15] = 1;
        } else {
          number_four[i][j - 15] = 0;
        }
      }
    }
  }
  int num_one = Check(number_one, numbers, 2);
  if (num_one == -1) {
    std::cout << "ERROR";
    return 0;
  }
  int num_two;
  if (num_one == 2) {
    num_two = Check(number_two, numbers, 3);
    if (num_two == -1) {
      std::cout << "ERROR";
      return 0;
    }
  } else {
    num_two = Check(number_two, numbers, 10);
    if (num_two == -1) {
      std::cout << "ERROR";
      return 0;
    }
  }
  int num_three = Check(number_three, numbers, 5);
  if (num_three == -1) {
    std::cout << "ERROR";
    return 0;
  }
  int num_four = Check(number_four, numbers, 10);
  if (num_four == -1) {
    std::cout << "ERROR";
    return 0;
  }
  if (num_one == 10 || num_two == 10 || num_three == 10 || num_four == 10) {
    std::cout << "AMBIGUITY";
    return 0;
  }
  std::cout << num_one << num_two << ':' << num_three << num_four;
  return 0;
}
