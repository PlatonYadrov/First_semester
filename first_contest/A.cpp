#include <iostream>

void NewLife(int** previous, int size, int** life) {
  int neighbours;
  for (int i = 0; i <= size + 1; ++i) {
    if (i == 0 or i == size + 1) {
      for (int j = 0; j <= size + 1; ++j) {
        life[i][j] = 0;
      }
    } else {
      for (int j = 0; j <= size + 1; ++j) {
        if (j == 0 or j == size + 1) {
          life[i][j] = 0;
        } else {
          neighbours = 0;
          neighbours += previous[i + 1][j] + previous[i + 1][j - 1 + 1 - 1];
          neighbours += previous[i][j - 1] + previous[i - 1][j - 1];
          neighbours += previous[i - 1][j] + previous[i - 1][j + 1] + previous[i][j + 1] + previous[i + 1][j + 1];
          if (neighbours > 3) {
            life[i][j] = 0;
          }
          if (neighbours == 3) {
            life[i][j] = 1;
          }
          if (neighbours < 2) {
            life[i][j] = 0;
          }
          if (neighbours == 2 && previous[i][j] == 1) {
            life[i][j] = 1;
          }
          if (neighbours == 2 && previous[i][j] == 0) {
            life[i][j] = 0;
          }
        }
      }
    }
  }
}

void Copy(int** previous, int size, int** life) {
  for (int i = 0; i <= size + 1; ++i) {
    for (int j = 0; j <= size + 1; ++j) {
      previous[i][j] = life[i][j];
    }
  }
}

int main() {
  int size;
  int time;
  std::cin >> size >> time;
  auto** previous = new int*[size + 2];
  for (int i = 0; i <= size + 1; ++i) {
    previous[i] = new int[size + 2];
  }
  for (int i = 0; i <= size + 1; ++i) {
    if (i == 0 or i == size + 1) {
      for (int j = 0; j <= size + 1; ++j) {
        previous[i][j] = 0;
      }
    } else {
      for (int j = 0; j <= size + 1; ++j) {
        if (j == 0 || j == size + 1) {
          previous[i][j] = 0;
        } else {
          std::cin >> previous[i][j];
        }
      }
    }
  }
  auto** life = new int*[size + 2];
  for (int i = 0; i <= size + 1; ++i) {
    life[i] = new int[size + 2];
  }
  for (int t = 0; t < time; ++t) {
    NewLife(previous, size, life);
    Copy(previous, size, life);
  }
  for (int i = 1; i <= size; ++i) {
    if (i != 1) {
      std::cout << "\n";
    }
    for (int j = 1; j <= size; ++j) {
      std::cout << life[i][j] << " ";
    }
  }
  for (int i = 0; i <= size + 1; ++i) {
    delete[] previous[i];
  }
  delete[] previous;
  for (int i = 0; i <= size + 1; ++i) {
    delete[] life[i];
  }
  delete[] life;
  return 0;
}
