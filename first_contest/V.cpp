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

void Solution(int n, int64_t *lenghths, int big_summ) {
  int while_summ = 0;
  int max = lenghths[2] + lenghths[1];
  int all = 2;
  for (int i = 0; i < n - 1; ++i) {
    while_summ += lenghths[i];
    int local_sum = lenghths[i] + lenghths[i + 1];
    int len = 2;
    int more_i = i + 2;
    while ((more_i < n) && (lenghths[more_i] + lenghths[more_i - 1] >= lenghths[i])) {
      local_sum += lenghths[more_i];
      ++len;
      ++more_i;
    }
    if (local_sum > max) {
      all = len;
      max = local_sum;
    }
    if (big_summ - while_summ < max) {
      break;
    }
  }
  std::cout << all << " " << max;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  int big_summ = 0;
  std::cin >> n;
  auto *lengths = new int64_t[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> lengths[i];
    big_summ += lengths[i];
  }
  MergeSort(lengths, n);
  auto *lengths_rev = new int64_t[n];
  for (int i = 0; i < n; i++) {
    lengths_rev[i] = lengths[n - 1 - i];
  }
  if (n == 1) {
    std::cout << 1 << " " << lengths[0];
    delete[] lengths;
    delete[] lengths_rev;
    return 0;
  }
  if (n == 2) {
    std::cout << 2 << " " << lengths[0] + lengths[1];
    delete[] lengths;
    delete[] lengths_rev;
    return 0;
  }
  Solution(n, lengths_rev, big_summ);
  delete[] lengths;
  delete[] lengths_rev;
  return 0;
}
