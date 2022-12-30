#include <iostream>
#ifndef Heap_H
#define Heap_H
template <class T>
void PushHeap(T* begin, T* end) {
  T* element = begin + (end - begin - 1);
  T* parent = begin + (end - begin - 2) / 2;
  while ((begin - element < 0) && (*parent < *element)) {
    T temp = *element;
    *element = *parent;
    *parent = temp;
    element = parent;
    parent = begin + (element - begin - 1) / 2;
  }
}

template <class T>
void PopHeap(T* begin, T* end) {
  T temp = *begin;
  *begin = *(end - 1);
  *(end - 1) = temp;
  T* parent = begin;
  T* left_child = begin + 2 * (parent - begin) + 1;
  T* right_child = begin + 2 * (parent - begin) + 2;
  while ((left_child < end - 1) || (right_child < end - 1)) {
    left_child = begin + 2 * (parent - begin) + 1;
    right_child = begin + 2 * (parent - begin) + 2;
    T* cell = parent;
    if ((left_child < end - 1) && (*cell < *left_child)) {
      cell = left_child;
    }
    if ((right_child < end - 1) && (*cell < *right_child)) {
      cell = right_child;
    }
    if (!((cell < parent) || (parent < cell))) {
      return;
    }
    temp = *parent;
    *parent = *cell;
    *cell = temp;
    parent = cell;
  }
}
#endif
