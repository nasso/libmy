/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Memory utils
*/

#ifndef LIBMY_MEM_H
#define LIBMY_MEM_H

#include "types.h"

void *my_malloc(usize_t size);
void my_free(void *ptr);
void *my_calloc(usize_t nmemb, usize_t size);
void *my_memset(void *s, u8_t c, usize_t n);
isize_t my_memshow(const void*, usize_t);

#endif /* LIBMY_MEM_H */
