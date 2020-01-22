/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Option type
*/

#ifndef LIBMY_OPTION_H
#define LIBMY_OPTION_H

#include <stdbool.h>
#include "priv/vaopt.h"

#define NAMED_OPTION(T, name) struct name { bool is_some; T v; }
#define OPTION(T) struct { bool is_some; T v; }
#define SOME(X, ...) { \
        .is_some = true, \
        .v = MY__VA_OPT({, __VA_ARGS__) \
            X, ##__VA_ARGS__ \
        MY__VA_OPT(}, __VA_ARGS__) \
    }
#define NONE { false }

#endif /* LIBMY_OPTION_H */
