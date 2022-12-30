#include <iostream>

void Merge(int64_t *target_arr, int64_t *arr_one, int64_t len_one, int64_t *arr_two, int64_t len_two) {
  int64_t one_min_id = 0;
  int64_t two_min_id = 0;
  int64_t target_min_id = 0;
  while ((one_min_id < len_one) && (two_min_id < len_two)) {
    if (arr_one[one_min_id] <= arr_two[two_min_id]) {
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

void MergeSort(int64_t *arr, int64_t amount) {
  if (amount < 2) {
    return;
  }
  int64_t middle = amount / 2;
  auto *left = new int64_t[middle];
  auto *right = new int64_t[amount - middle];
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

int Check(int middle, int n, int m, int k, int64_t *differences) {
  int border_one = 0;
  int border_two = 0;
  for (int i = 0; i < n - k + 1; ++i) {
    --border_two;
    if (border_two < 1 && differences[i] <= middle) {
      ++border_one;
      border_two = k;
    }
  }
  if (border_one >= m) {
    return 1;
  }
  return 0;
}

int Solution(int n, int m, int k, int64_t *people) {
  auto *differences = new int64_t[n - k + 1];
  for (int i = 0; i < n - k + 1; ++i) {
    differences[i] = people[i + k - 1] - people[i];
  }
  int left = -1;
  int right = people[n - 1] - people[0];
  int middle;
  int check;
  if (m > 1) {
    while (left != right - 1) {
      middle = (left + right) / 2;
      check = Check(middle, n, m, k, differences);
      if (check == 1) {
        right = middle;
      } else {
        left = middle;
      }
    }
    delete[] differences;
    return right;
  }
  int min = 100000000;
  for (int i = 0; i < n - k + 1; ++i) {
    if (differences[i] < min) {
      min = differences[i];
    }
  }
  delete[] differences;
  return min;
}

int main() {
  int n;
  int m;
  int k;
  std::cin >> n >> m >> k;
  auto *people = new int64_t[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> people[i];
  }
  MergeSort(people, n);
  std::cout << Solution(n, m, k, people);
  delete[] people;
  return 0;
}
