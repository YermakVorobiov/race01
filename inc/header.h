#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void check(char* argv[], char* operand1, char* operation, char* operand2, char* result);
char* delete_space(const char* str);
void equation(char* argv[], char* operand1, char* operation, char* operand2, char* result);
long long mx_atoi(const char* str);
bool mx_isdigit(int c);
bool mx_isspace(int c);
char* mx_itoa(long long number);
double mx_pow(double n, unsigned int pow);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char* s);
void mx_str_reverse(char* s);
char* mx_strcpy(char* dst, const char* src);
int mx_strlen(const char* s);
char* mx_strncpy(char* dst, const char* src, int len);
char* mx_strndup(const char* s1, int n);
char* mx_strnew(const int size);
void mx_swap_char(char* s1, char* s2);
int mx_strcmp(const char* s1, const char* s2);

#endif

