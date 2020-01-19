/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Result type
*/

#ifndef LIBMY_RESULT_H
#define LIBMY_RESULT_H

#include <stdbool.h>

#define NAMED_RESULT(T, E, name) \
    struct name { bool is_ok; union { T ok; E err; } u; }
#define RESULT(T, E) NAMED_RESULT(T, E,)
#define OK(X, ...) { \
        .is_ok = true, \
        .u.ok = __VA_OPT__({) X __VA_OPT__(,) __VA_ARGS__ __VA_OPT__(}) \
    }
#define ERR(X, ...) { \
        .is_ok = false, \
        .u.err = __VA_OPT__({) X __VA_OPT__(,) __VA_ARGS__ __VA_OPT__(}) \
    }

#endif /* LIBMY_RESULT_H */
