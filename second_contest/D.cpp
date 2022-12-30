#ifndef Heap
#define Heap
template <class T>
void MakeHeap(T* begin, T* end) {
  int n = end - begin;
  for (int i = n / 2 - 1; i >= 0; i--) {
    int max = i;
    while (true) {
      int max_old = max;
      int left = 2 * max + 1;
      int right = 2 * max + 2;
      if ((left < n) && (*(begin + max) < *(begin + left))) {
        max = left;
      }
      if ((right < n) && (*(begin + max) < *(begin + right))) {
        max = right;
      }
      if (max != max_old) {
        T temp = *(begin + max_old);
        *(begin + max_old) = *(begin + max);
        *(begin + max) = temp;
      }
      if (max == max_old) {
        break;
      }
    }
  }
}

template <class T>
void SortHeap(T* begin, T* end) {
  MakeHeap(begin, end);
  for (int j = end - begin - 1; j >= 0; --j) {
    int n = j;
    T temp = *(begin);
    *(begin) = *(begin + j);
    *(begin + j) = temp;
    int max = 0;
    while (true) {
      int max_old = max;
      int left = 2 * max + 1;
      int right = 2 * max + 2;
      if ((left < n) && (*(begin + max) < *(begin + left))) {
        max = left;
      }
      if ((right < n) && (*(begin + max) < *(begin + right))) {
        max = right;
      }
      if (max != max_old) {
        T temp = *(begin + max_old);
        *(begin + max_old) = *(begin + max);
        *(begin + max) = temp;
      }
      if (max == max_old) {
        break;
      }
    }
  }
}
#endif
