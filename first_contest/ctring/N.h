#ifndef STRING_H
#define STRING_H

size_t Strlen(const char*);

int Strcmp(const char*, const char*);

int Strncmp(const char*, const char*, size_t);

char* Strcpy(char*, const char*);

char* Strncpy(char*, const char*, size_t);

char* Strcat(char*, const char*);

char* Strncat(char*, const char*, size_t);

const char* Strchr(const char*, char);

const char* Strrchr(const char*, char);

size_t Strspn(const char*, const char*);

size_t Strcspn(const char*, const char*);

const char* Strpbrk(const char*, const char*);

const char* Strstr(const char*, const char*);

#endif
