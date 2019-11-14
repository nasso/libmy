/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** libmy header file.
*/

#ifndef LIBMY_H_
#define LIBMY_H_

#include <stdarg.h>
#include "stream/bufwriter.h"

#define MY_UNUSED(X) (void)(X)
#define MY_MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MY_MAX(X, Y) ((X) < (Y) ? (Y) : (X))

void my_putchar(char c);
void my_putchar_err(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putstr_err(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char const *my_strchr(char const *str, char c);
char const *my_strrchr(char const *str, char c);
char const *my_strchrnul(char const *str, char c);
char *my_strchr_mut(char *str, char c);
char *my_strrchr_mut(char *str, char c);
char *my_strchrnul_mut(char *str, char c);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_getnbr_base(char const *str, char const *base);
int my_putnbr_base(int nbr, char const *base, char *dest);
int my_show_word_array(char * const*);
int my_vbufprintf(bufwriter_t*, char const*, va_list);
int my_vfprintf(int fd, char const*, va_list);
int my_fprintf(int fd, char const*, ...);
int my_printf(char const*, ...);
char *my_format(char const*, ...);

#endif
