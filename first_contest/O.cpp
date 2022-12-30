#include <iostream>
#ifndef BIN
#define BIN

template <class T>
bool BinarySearch(const T* begin, const T* end, const T& value) {
  int left = -1;
  int right = end - begin;
  int middle;
  while (left < right - 1) {
    middle = right + (left - right) / 2;
    if (*(begin + middle) < value) {
      left = middle;
    } else {
      right = middle;
    }
  }
  if (right < end - begin) {
    if (!((*(begin + right) < value) || (value < *(begin + right)))) {
      return true;
    }
    return false;
  }
  return false;
}

template <class T>
const T* LowerBound(const T* begin, const T* end, const T& value) {
  int left = -1;
  int right = end - begin;
  int middle;
  while (left - right < -1) {
    middle = right + (left - right) / 2;
    if (*(middle + begin) < value) {
      left = middle;
    } else {
      right = middle;
    }
  }
  return (begin + right);
}

template <class T>
const T* UpperBound(const T* begin, const T* end, const T& value) {
  int left = -1;
  int right = end - begin;
  int middle;
  while (left - right < -1) {
    middle = right + (left - right) / 2;
    if (value < *(middle + begin)) {
      right = middle;
    } else {
      left = middle;
    }
  }
  return (begin + right);
}

#endif
