/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** C-string utils
*/

#ifndef LIBMY_CSTR_H
#define LIBMY_CSTR_H

#include <stddef.h>
#include <stdbool.h>
#include "my/types.h"

size_t my_cstrlen(const char*);
char *my_cstrdup(const char*);
char *my_cstrndup(const char*, size_t);
char *my_cstrcat(char*, const char*);
char *my_cstrncat(char*, const char*, size_t);
char *my_cstrcpy(char*, const char*);
char *my_cstrncpy(char*, const char*, size_t);
char *my_cstrrev(char*);
char *my_cstrstr(char*, const char*);
const char *my_cstrchr(const char*, char);
const char *my_cstrrchr(const char*, char);
const char *my_cstrchrnul(const char*, char);
char *my_cstrchr_mut(char*, char);
char *my_cstrrchr_mut(char*, char);
char *my_cstrchrnul_mut(char*, char);
int my_cstrcmp(const char*, const char*);
int my_cstrncmp(const char*, const char*, size_t);
char *my_cstrupcase(char*);
char *my_cstrlowcase(char*);
char *my_cstrcapitalize(char*);
bool my_cstr_isalpha(const char*);
bool my_cstr_isnum(const char*);
bool my_cstr_islower(const char*);
bool my_cstr_isupper(const char*);
bool my_cstr_isprintable(const char*);
int my_cstr_getnbr_base(const char*, const char*);
int my_cstr_getnbr(const char*);
opt_i32_t my_cstr_indexof(const char*, char);

#endif /* LIBMY_CSTR_H */
