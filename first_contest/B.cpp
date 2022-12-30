#include <iostream>

void Line(int *lines, int number1, int *deltax, int units, char **array, int height, int lenght) {
  for (int i = 0; i < height; ++i) {
    units = 0;
    for (int j = 0; j < lenght; ++j) {
      if (array[i][j] == '1') {
        units += 1;
        if (units == lenght) {
          *lines += 1;
          if (*lines == 2) {
            *deltax = i - number1 - 1;
          } else {
            number1 = i;
          }
        }
      } else {
        break;
      }
    }
  }
}

void VertLine(int *vertlines, int number1, int *deltay, int units, char **array, int height, int lenght) {
  for (int j = 0; j < lenght; ++j) {
    units = 0;
    for (int i = 0; i < height; ++i) {
      if (array[i][j] == '1') {
        units += 1;
        if (units == height) {
          *vertlines += 1;
          if (*vertlines == 2) {
            *deltay = j - number1 - 1;
          } else {
            number1 = j;
          }
        }
      } else {
        break;
      }
    }
  }
}

int main() {
  int height;
  int lenght;
  std::cin >> height >> lenght;
  auto **array = new char *[height];
  for (int i = 0; i < height; ++i) {
    array[i] = new char[lenght + 1];
  }
  for (int i = 0; i < height; ++i) {
    std::cin >> array[i];
  }
  int lines = 0;
  int number1 = 0;
  int deltax = 0;
  int units = 0;
  Line(&lines, number1, &deltax, units, array, height, lenght);
  int vertlines = 0;
  int deltay = 0;
  VertLine(&vertlines, number1, &deltay, units, array, height, lenght);
  if (lines > 0 && vertlines > 0 && lenght > 1 && height > 1) {
    std::cout << "Square";
  } else if (deltax >= lenght || lines == 1 || deltay >= height || vertlines == 1 || (lines == 0 && vertlines == 0)) {
    std::cout << "?";
  } else if (lines > 0) {
    std::cout << "Line";
  } else {
    std::cout << "Vertical line";
  }
  for (int i = 0; i < height; ++i) {
    delete[] array[i];
  }
  delete[] array;
  return 0;
}
