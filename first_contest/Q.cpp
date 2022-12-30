#include <iostream>
#ifndef Sort_H
#define Sort_H
template <class T>
void Sort(T* begin, T* end) {
  int amount = end - begin;
  if (amount < 2) {
    return;
  }
  int middle = (end - begin) / 2;
  Sort(begin, begin + middle);
  Sort(begin + middle, end);
  T temp_arr[1000003];
  T* begin1 = begin;
  T* begin2 = begin + middle;
  int k = 0;
  while ((begin1 - begin - middle < 0) && (begin2 - end < 0)) {
    if (*begin1 < *begin2) {
      temp_arr[k] = *begin1;
      ++begin1;
    } else {
      temp_arr[k] = *begin2;
      ++begin2;
    }
    ++k;
  }
  while (begin1 - begin < middle) {
    temp_arr[k] = *begin1;
    ++begin1;
    ++k;
  }
  while (begin2 < end) {
    temp_arr[k] = *begin2;
    ++begin2;
    ++k;
  }
  for (int i = 0; i < k; ++i) {
    *begin = temp_arr[i];
    ++begin;
  }
}
#endif
