#include <iostream>
#ifndef KthElement_H
#define KthElement_H
template <class T>
void KthElement(T* begin, T* kth, T* end) {
  --end;
  while (!(end - begin < 0)) {
    if (!((end - begin < 1) || (1 < end - begin)) && (*end < *begin)) {
      T temp = *begin;
      *begin = *end;
      *end = temp;
    }
    if (end - begin < 2) {
      return;
    }
    if (*end < *begin) {
      T temp = *begin;
      *begin = *end;
      *end = temp;
    }
    if (*end < *(begin + 1)) {
      T temp = *(begin + 1);
      *(begin + 1) = *end;
      *end = temp;
    }
    if (*(begin + 1) < *begin) {
      T temp = *begin;
      *begin = *(begin + 1);
      *(begin + 1) = temp;
    }
    T* left = begin + 1;
    T pivot = *left;
    T* right = end;
    while (!(right - left < 0)) {
      while (*(left + 1) < pivot) {
        ++left;
      }
      ++left;
      while (pivot < *(right - 1)) {
        --right;
      }
      --right;
      if (right - left < 0) {
        break;
      }
      T temp = *left;
      *left = *right;
      *right = temp;
    }
    T temp = *right;
    *right = *(begin + 1);
    *(begin + 1) = temp;
    if (!(right < kth)) {
      end = right - 1;
    }
    if (!(kth < left)) {
      begin = left;
    }
  }
}
#endif
