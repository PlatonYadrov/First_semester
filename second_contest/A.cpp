#include <iostream>

struct Exam {
  int score;
  char name[100];
};

void Merge(Exam *target_arr, Exam *arr_one, int64_t len_one, Exam *arr_two, int64_t len_two) {
  int64_t one_min_id = 0;
  int64_t two_min_id = 0;
  int64_t target_min_id = 0;
  while ((one_min_id < len_one) && (two_min_id < len_two)) {
    if (arr_one[one_min_id].score >= arr_two[two_min_id].score) {
      target_arr[target_min_id] = arr_one[one_min_id];
      ++one_min_id;
    } else {
      target_arr[target_min_id] = arr_two[two_min_id];
      ++two_min_id;
    }
    ++target_min_id;
  }
  while (one_min_id < len_one) {
    target_arr[target_min_id] = arr_one[one_min_id];
    ++one_min_id;
    ++target_min_id;
  }
  while (two_min_id < len_two) {
    target_arr[target_min_id] = arr_two[two_min_id];
    ++two_min_id;
    ++target_min_id;
  }
}

void MergeSort(Exam *arr, int64_t amount) {
  if (amount < 2) {
    return;
  }
  int64_t middle = amount / 2;
  auto *left = new Exam[middle];
  auto *right = new Exam[amount - middle];
  for (int64_t i = 0; i < middle; ++i) {
    left[i] = arr[i];
  }
  for (int64_t i = middle; i < amount; ++i) {
    right[i - middle] = arr[i];
  }
  MergeSort(left, middle);
  MergeSort(right, amount - middle);
  Merge(arr, left, middle, right, amount - middle);
  delete[] left;
  delete[] right;
}

int main() {
  int64_t amount;
  std::cin >> amount;
  Exam students[1000010];
  for (int k = 0; k < amount; ++k) {
    int i = 0;
    int p = 0;
    char str[100];
    int inf = 0;
    int math = 0;
    int russ = 0;
    int spaces = 0;
    if (k == 0) {
      std::cin >> students[0].name[i];
      p = 1;
    }
    for (i = p; true; ++i) {
      str[i] = getchar();
      students[k].name[i] = str[i];
      if (str[i] == ' ') {
        ++spaces;
        if (spaces == 2) {
          students[k].name[i] = '\0';
          break;
        }
      }
    }
    std::cin >> inf >> math >> russ;
    students[k].score = inf + math + russ;
  }
  MergeSort(students, amount);
  for (int i = 0; i < amount; ++i) {
    std::cout << students[i].name << '\n';
  }
  return 0;
}
