#include <iostream>
#include "cstring.h"

size_t Strlen(const char* str) {
  size_t i = 0;
  while (str[i] != '\0') {
    ++i;
  }
  return i;
}

int Strcmp(const char* first, const char* second) {
  int i = 0;
  for (; first[i] == second[i]; ++i) {
    if (first[i] == '\0') {
      return 0;
    }
  }
  if (first[i] > second[i]) {
    return 1;
  }
  return -1;
}

int Strncmp(const char* first, const char* second, size_t count) {
  size_t i = 0;
  if (count == 0) {
    return 0;
  }
  for (; (first[i] == second[i]) && (i < count); ++i) {
    if (first[i] == '\0') {
      return 0;
    }
  }
  if (i < count) {
    if (first[i] > second[i]) {
      return 1;
    }
    return -1;
  }
  return 0;
}

char* Strcpy(char* dest, const char* src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    ++i;
  }
  dest[i] = src[i];
  return dest;
}

char* Strncpy(char* dest, const char* src, size_t count) {
  size_t i = 0;
  for (; (i < count) && (src[i] != '\0'); ++i) {
    dest[i] = src[i];
  }
  for (; i < count; ++i) {
    dest[i] = '\0';
  }
  return dest;
}

char* Strcat(char* dest, const char* src) {
  int i = 0;
  int j = 0;
  while (dest[i] != 0) {
    ++i;
  }
  while (src[j] != '\0') {
    dest[i + j] = src[j];
    j++;
  }
  dest[i + j] = src[j];
  return dest;
}

char* Strncat(char* dest, const char* src, size_t count) {
  size_t i = 0;
  int j = 0;
  while (dest[j] != '\0') {
    ++j;
  }
  while ((src[i] != '\0') && (i < count)) {
    dest[j + i] = src[i];
    ++i;
  }
  dest[j + i] = '\0';
  return dest;
}

const char* Strchr(const char* str, char symbol) {
  int i = 0;
  while ((str[i] != '\0') && (str[i] != symbol)) {
    ++i;
  }
  if (str[i] == symbol) {
    return str + i;
  }
  return nullptr;
}

const char* Strrchr(const char* str, char symbol) {
  int i = 0;
  while (str[i] != '\0') {
    ++i;
  }
  while ((str[i] != symbol) && (i != 0)) {
    --i;
  }
  if (str[i] == symbol) {
    return str + i;
  }
  return nullptr;
}

size_t Strspn(const char* dest, const char* src) {
  size_t i = 0;
  while ((dest[i] != '\0') && (Strchr(src, dest[i]))) {
    ++i;
  }
  return i;
}

size_t Strcspn(const char* dest, const char* src) {
  size_t i = 0;
  while ((dest[i] != '\0') && !(Strchr(src, dest[i]))) {
    ++i;
  }
  return i;
}

const char* Strpbrk(const char* dest, const char* breakset) {
  int number = Strcspn(dest, breakset);
  if (dest[number] != '\0') {
    return dest + number;
  }
  return nullptr;
}

const char* Strstr(const char* str1, const char* str2) {
  int i = 0;
  if (*str2 == '\0') {
    return str1;
  }
  while (*(str1 + i) != '\0') {
    int j = 0;
    while ((*(str1 + i + j) != '\0') && (*(str2 + j) != '\0') && (*(str1 + i + j) == *(str2 + j))) {
      ++j;
    }
    if (*(str2 + j) == '\0') {
      return str1 + i;
    }
    ++i;
  }
  return nullptr;
}
