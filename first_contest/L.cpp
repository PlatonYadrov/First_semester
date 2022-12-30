#include <iostream>

int Partition(int *arr, int start, int end) {
  int var = arr[end];
  int position = start;
  for (int i = start; i < end; ++i) {
    if (arr[i] <= var) {
      int temp = arr[i];
      arr[i] = arr[position];
      arr[position] = temp;
      ++position;
    }
  }
  arr[end] = arr[position];
  arr[position] = var;
  return position;
}

void QuickSort(int *arr, int start, int end) {
  if (start >= end) {
    return;
  }
  int pivot = Partition(arr, start, end);
  QuickSort(arr, start, pivot - 1);
  QuickSort(arr, pivot + 1, end);
}

int BinSearch(int *arr, int end, int element) {
  int start = -1;
  int middle;
  while (start < end - 1) {
    middle = (start + end) / 2;
    if (arr[middle] < element) {
      start = middle;
    } else {
      end = middle;
    }
  }
  return end;
}

int Check(int *arr_one, int end_one, int *arr_two, int end_two) {
  int search;
  for (int i = 0; i < end_one; ++i) {
    search = BinSearch(arr_two, end_two, arr_one[i]);
    if ((search >= end_two) || (arr_two[search] != arr_one[i])) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int amount_one;
  int amount_two;
  int check = 1;
  int start = 0;
  std::cin >> amount_one;
  auto *array_one = new int[amount_one];
  for (int i = 0; i < amount_one; ++i) {
    std::cin >> array_one[i];
  }
  amount_one -= 1;
  QuickSort(array_one, start, amount_one);
  std::cin >> amount_two;
  auto *array_two = new int[amount_two];
  for (int i = 0; i < amount_two; ++i) {
    std::cin >> array_two[i];
  }
  amount_two -= 1;
  QuickSort(array_two, start, amount_two);
  amount_one += 1;
  amount_two += 1;
  check *= Check(array_one, amount_one, array_two, amount_two);
  check *= Check(array_two, amount_two, array_one, amount_one);
  if (check) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  delete[] array_one;
  delete[] array_two;
  return 0;
}
