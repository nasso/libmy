/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Path manipulation utils
*/

#ifndef LIBMY_PATH_H
#define LIBMY_PATH_H

#include "my/types.h"

typedef char *path_t;

path_t path_from(const char *str);
void path_free(path_t self);
bool path_eq(const path_t self, const path_t other);
path_t path_parent(const path_t self);
path_t path_join(const path_t self, const path_t other);
bool path_is_abs(const path_t self);
bool path_is_rel(const path_t self);
char *path_file_name(const path_t self);
char *path_extension(const path_t self);

#endif /* LIBMY_PATH_H */
