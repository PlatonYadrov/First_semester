#ifndef MATRIX
#define MATRIX

#include <stdexcept>
#include <iostream>

class MatrixOutOfRange : public std::out_of_range {
 public:
  MatrixOutOfRange() : std::out_of_range("MatrixOutOfRange") {
  }
};

template <class T, size_t N, size_t M>
class Matrix {
 public:
  T matrix[N][M];
  size_t RowsNumber() const {
    return N;
  }

  size_t ColumnsNumber() const {
    return M;
  }

  const T& operator()(size_t n, size_t m) const {
    return matrix[n][m];
  }

  T& operator()(size_t n, size_t m) {
    return matrix[n][m];
  }

  T& At(size_t n, size_t m) {
    if (!((m >= M) || (n >= N))) {
      return matrix[n][m];
    }
    throw MatrixOutOfRange();
  }

  const T& At(size_t n, size_t m) const {
    if (!((m >= M) || (n >= N))) {
      return matrix[n][m];
    }
    throw MatrixOutOfRange();
  }

  Matrix<T, N, M>& operator+=(Matrix<T, N, M> more) {
    for (size_t n = 0; n < N; ++n) {
      for (size_t m = 0; m < M; ++m) {
        matrix[n][m] += more(n, m);
      }
    }
    return *this;
  }

  Matrix<T, N, M>& operator-=(Matrix<T, N, M> more) {
    for (size_t n = 0; n < N; ++n) {
      for (size_t m = 0; m < M; ++m) {
        matrix[n][m] -= more(n, m);
      }
    }
    return *this;
  }

  Matrix<T, N, M>& operator*=(Matrix<T, M, M> more) {
    Matrix<T, N, M> temp_matrix;
    for (size_t n = 0; n < N; ++n) {
      for (size_t m = 0; m < M; ++m) {
        temp_matrix(n, m) = 0;
      }
    }
    for (size_t n = 0; n < N; ++n) {
      for (size_t m = 0; m < M; ++m) {
        for (size_t more_m = 0; more_m < M; ++more_m) {
          temp_matrix(n, m) += matrix[n][more_m] * more(more_m, m);
        }
      }
    }
    for (size_t n = 0; n < N; ++n) {
      for (size_t m = 0; m < M; ++m) {
        matrix[n][m] = temp_matrix(n, m);
      }
    }
    return *this;
  }

  Matrix<T, N, M>& operator*=(double var) {
    for (size_t n = 0; n < N; ++n) {
      for (size_t m = 0; m < M; ++m) {
        matrix[n][m] *= var;
      }
    }
    return *this;
  }

  Matrix<T, N, M>& operator/=(double var) {
    for (size_t n = 0; n < N; ++n) {
      for (size_t m = 0; m < M; ++m) {
        matrix[n][m] /= var;
      }
    }
    return *this;
  }
};

template <class T, size_t N, size_t M>
Matrix<T, N, M> Zeros(Matrix<T, N, M>& third) {
  for (size_t n = 0; n < N; ++n) {
    for (size_t m = 0; m < M; ++m) {
      third(n, m) = 0;
    }
  }
  return third;
}

template <class T, size_t N, size_t M>
Matrix<T, M, N> GetTransposed(Matrix<T, N, M> reference) {
  Matrix<T, M, N> transposed;
  for (size_t n = 0; n < N; ++n) {
    for (size_t m = 0; m < M; ++m) {
      transposed(m, n) = reference(n, m);
    }
  }
  return transposed;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator+(Matrix<T, N, M> first, Matrix<T, N, M> second) {
  Matrix<T, N, M> third;
  for (size_t n = 0; n < N; ++n) {
    for (size_t m = 0; m < M; ++m) {
      third(n, m) = first(n, m) + second(n, m);
    }
  }
  return third;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator-(Matrix<T, N, M> first, Matrix<T, N, M> second) {
  Matrix<T, N, M> third;
  for (size_t n = 0; n < N; ++n) {
    for (size_t m = 0; m < M; ++m) {
      third(n, m) = first(n, m) - second(n, m);
    }
  }
  return third;
}

template <class T, size_t N, size_t M, size_t A>
Matrix<T, N, M> operator*(Matrix<T, N, A> first, Matrix<T, A, M> second) {
  Matrix<T, N, M> third = Zeros(third);
  for (size_t n = 0; n < N; ++n) {
    for (size_t m = 0; m < M; ++m) {
      for (size_t a = 0; a < A; ++a) {
        third(n, m) += first(n, a) * second(a, m);
      }
    }
  }
  return third;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator*(Matrix<T, N, M> matr, double var) {
  Matrix<T, N, M> new_matrix = matr;
  for (size_t n = 0; n < N; ++n) {
    for (size_t m = 0; m < M; ++m) {
      new_matrix(n, m) *= var;
    }
  }
  return new_matrix;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator*(double var, Matrix<T, N, M> matr) {
  return matr * var;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator/(Matrix<T, N, M> matr, double var) {
  Matrix<T, N, M> new_matrix = matr;
  for (size_t n = 0; n < N; ++n) {
    for (size_t m = 0; m < M; ++m) {
      new_matrix(n, m) /= var;
    }
  }
  return new_matrix;
}

template <class T, size_t N, size_t M>
bool operator==(Matrix<T, N, M> first, Matrix<T, N, M> second) {
  bool ancoincidence = true;
  for (size_t n = 0; n < N; ++n) {
    for (size_t m = 0; m < M; ++m) {
      if (first(n, m) != second(n, m)) {
        ancoincidence = false;
        break;
      }
    }
    if (!ancoincidence) {
      break;
    }
  }
  return ancoincidence;
}

template <class T, size_t N, size_t M>
bool operator!=(Matrix<T, N, M> first, Matrix<T, N, M> second) {
  return !(first == second);
}

template <class T, size_t N, size_t M>
std::istream& operator>>(std::istream& element, Matrix<T, N, M>& matr) {
  for (size_t n = 0; n < N; ++n) {
    for (size_t m = 0; m < M; ++m) {
      element >> matr.matrix[n][m];
    }
  }
  return element;
}

template <class T, size_t N, size_t M>
std::ostream& operator<<(std::ostream& element, const Matrix<T, N, M>& matr) {
  for (size_t n = 0; n < N; ++n) {
    for (size_t m = 0; m < M; ++m) {
      if (m == M - 1) {
        element << matr(n, m) << '\n';
      } else {
        element << matr(n, m) << " ";
      }
    }
  }
  return element;
}

#endif
