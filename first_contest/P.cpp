#include <iostream>
#ifndef MERGE_H
#define MERGE_H
template <class T1, class T2, class T3>
void Merge(const T1* first_begin, const T1* first_end, const T2* second_begin, const T2* second_end, T3* out) {
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
}
#endif
