#ifndef ARRAY
#define ARRAY
#include <stdexcept>

class ArrayOutOfRange : public std::out_of_range {
 public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
  }
};

template <class T, size_t K>
class Array {
 public:
  T arr[K];
  T& operator[](size_t index);
  const T& operator[](size_t index) const;
  const T& At(size_t) const;
  T& At(size_t);
  const T& Front() const;
  T& Front();
  const T& Back() const;
  T& Back();
  const T* Data() const;
  T* Data();
  size_t Size() const;
  bool Empty() const;
  void Fill(const T& value);
  void Swap(Array<T, K>& other);
};

template <class T, size_t K>
const T* Array<T, K>::Data() const {
  return arr;
}

template <class T, size_t K>
T* Array<T, K>::Data() {
  return arr;
}

template <class T, size_t K>
size_t Array<T, K>::Size() const {
  return K;
}

template <class T, size_t K>
bool Array<T, K>::Empty() const {
  if (Size() == 0) {
    return Size() == 0;
  }
  return Size() == 0;
}

template <class T, size_t K>
const T& Array<T, K>::At(size_t index) const {
  if (index < 0 || index >= K) {
    throw ArrayOutOfRange{};
  }
  return *(arr + index);
}

template <class T, size_t K>
T& Array<T, K>::At(size_t index) {
  if (index < 0 || index >= K) {
    throw ArrayOutOfRange{};
  }
  return *(arr + index);
}

template <class T, size_t K>
const T& Array<T, K>::Front() const {
  return *arr;
}

template <class T, size_t K>
T& Array<T, K>::Front() {
  return *arr;
}

template <class T, size_t K>
const T& Array<T, K>::Back() const {
  return *(arr + K - 1);
}

template <class T, size_t K>
T& Array<T, K>::Back() {
  return *(arr + K - 1);
}

template <class T, size_t K>
void Array<T, K>::Fill(const T& value) {
  for (size_t i = 0; i < K; ++i) {
    *(arr + i) = value;
  }
}

template <class T, size_t K>
T& Array<T, K>::operator[](size_t index) {
  return *(arr + index);
}

template <class T, size_t K>
const T& Array<T, K>::operator[](size_t index) const {
  return *(arr + index);
}

template <class T, size_t K>
void Array<T, K>::Swap(Array<T, K>& other) {
  for (size_t i = 0; i < K; ++i) {
    T temp = *(arr + i);
    *(arr + i) = other[i];
    other[i] = temp;
  }
}
#endif
