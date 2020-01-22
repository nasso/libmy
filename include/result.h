/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Result type
*/

#ifndef LIBMY_RESULT_H
#define LIBMY_RESULT_H

#include <stdbool.h>
#include "priv/vaopt.h"

#define NAMED_RESULT(T, E, name) \
    struct name { bool is_ok; union { T ok; E err; } u; }
#define RESULT(T, E) NAMED_RESULT(T, E,)
#define OK(X, ...) { \
        .is_ok = true, \
        .u.ok = MY__VA_OPT({, __VA_ARGS__) \
            X, ##__VA_ARGS__ \
        MY__VA_OPT(}, __VA_ARGS__) \
    }
#define ERR(X, ...) { \
        .is_ok = false, \
        .u.err = MY__VA_OPT({, __VA_ARGS__) \
            X, ##__VA_ARGS__ \
        MY__VA_OPT(}, __VA_ARGS__) \
    }

#endif /* LIBMY_RESULT_H */
