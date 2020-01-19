/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Option type
*/

#ifndef LIBMY_OPTION_H
#define LIBMY_OPTION_H

#include <stdbool.h>

#define NAMED_OPTION(T, name) struct name { bool is_some; T v; }
#define OPTION(T) struct { bool is_some; T v; }
#define SOME(X, ...) \
    { true, __VA_OPT__({) X __VA_OPT__(,) __VA_ARGS__ __VA_OPT__(}) }
#define NONE { false }

#endif /* LIBMY_OPTION_H */
