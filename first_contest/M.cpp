#include <iostream>

int64_t Merge(int64_t *target_arr, int64_t *arr_one, int64_t len_one, int64_t *arr_two, int64_t len_two) {
  int64_t one_min_id = 0;
  int64_t two_min_id = 0;
  int64_t target_min_id = 0;
  int64_t count = 0;
  while ((one_min_id < len_one) && (two_min_id < len_two)) {
    if (arr_one[one_min_id] <= arr_two[two_min_id]) {
      target_arr[target_min_id] = arr_one[one_min_id];
      ++one_min_id;
    } else {
      target_arr[target_min_id] = arr_two[two_min_id];
      ++two_min_id;
      count += len_one - one_min_id;
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
  return count;
}

int64_t MergeSort(int64_t *arr, int64_t amount) {
  if (amount < 2) {
    return 0;
  }
  int64_t count = 0;
  int64_t middle = amount / 2;
  auto *left = new int64_t[middle];
  auto *right = new int64_t[amount - middle];
  for (int64_t i = 0; i < middle; ++i) {
    left[i] = arr[i];
  }
  for (int64_t i = middle; i < amount; ++i) {
    right[i - middle] = arr[i];
  }
  count += MergeSort(left, middle);
  count += MergeSort(right, amount - middle);
  count += Merge(arr, left, middle, right, amount - middle);
  delete[] left;
  delete[] right;
  return count;
}

int main() {
  int64_t amount;
  int64_t all;
  std::cin >> amount;
  auto *array = new int64_t[amount];
  for (int64_t i = 0; i < amount; ++i) {
    std::cin >> array[i];
  }
  all = MergeSort(array, amount);
  std::cout << all;
  delete[] array;
  return 0;
}
