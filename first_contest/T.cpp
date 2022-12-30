#include <iostream>

void Update(int* finish_index, int& k) {
  auto* temp_arr = new int[k];
  if (k % 2 == 1) {
    k = k / 2 + 1;
    for (int i = 0; i < k; ++i) {
      temp_arr[i] = finish_index[i * 2];
    }
  } else {
    k = k / 2;
    for (int i = 0; i < k; ++i) {
      temp_arr[i] = finish_index[i * 2];
    }
    temp_arr[k] = finish_index[(k - 1) * 2 + 1];
    k += 1;
  }
  for (int i = 0; i < k; ++i) {
    finish_index[i] = temp_arr[i];
  }
  delete[] temp_arr;
}

void Merge(int* first_begin, int* first_end, int* second_begin, int* second_end) {
  int size = second_end - first_begin;
  int* start = first_begin;
  auto* out = new int[size];
  while ((first_begin - first_end < 0) && (second_begin - second_end < 0)) {
    if (*first_begin < *second_begin) {
      *out = *first_begin;
      ++first_begin;
    } else {
      *out = *second_begin;
      ++second_begin;
    }
    ++out;
  }
  while (first_begin - first_end < 0) {
    *out = *first_begin;
    ++first_begin;
    ++out;
  }
  while (second_begin - second_end < 0) {
    *out = *second_begin;
    ++second_begin;
    ++out;
  }
  for (int i = 0; i < size; ++i) {
    *(start + i) = *(out - size + i);
  }
  delete[](out - size);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int k;
  std::cin >> k;
  k += 1;
  auto* big_arr = new int[1000001];
  for (int i = 0; i < 1000001; ++i) {
    big_arr[i] = 1000000001;
  }
  int now_index_big_arr = 0;
  auto* finish_index = new int[k];
  finish_index[0] = 0;
  int small_amount;
  for (int i = 0; i < k - 1; ++i) {
    std::cin >> small_amount;
    finish_index[i + 1] = finish_index[i] + small_amount;
    for (int j = 0; j < small_amount; ++j) {
      std::cin >> big_arr[now_index_big_arr];
      ++now_index_big_arr;
    }
  }
  while (k > 2) {
    for (int i = 0; i < k - 1; i += 2) {
      if (i + 2 > k - 1) {
        continue;
      }
      int ptr_one = finish_index[i];
      int ptr_two = finish_index[i + 1];
      int ptr_three = finish_index[i + 2];
      Merge(big_arr + ptr_one, big_arr + ptr_two, big_arr + ptr_two, big_arr + ptr_three);
    }
    Update(finish_index, k);
  }
  for (int j = 0; j < finish_index[k - 1]; ++j) {
    std::cout << big_arr[j] << " ";
  }
  delete[] big_arr;
  delete[] finish_index;
  return 0;
}
