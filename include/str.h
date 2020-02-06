/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** str_t data type
*/

#ifndef LIBMY_STR_H
#define LIBMY_STR_H

#include "my/types.h"

#define STR(literal) {.ptr = literal, .len = sizeof(literal)}

typedef struct {
    const char *ptr;
    const usize_t len;
} str_t;

//! \fn str_t strs(const char *cstr, usize_t from, usize_t to);
//! \brief create a \c str_t that represents a slice of the given c-string
//! \param cstr the c-string
//! \param from the index of the first character in the slice (included)
//! \param to the index of the first character after the slice (excluded)
//! \return a new \c str_t
str_t strs(const char*, usize_t, usize_t);

//! \fn str_t strl(const char *cstr, usize_t len);
//! \brief create a \c str_t containing only the first \c len chars of \c cstr
//! \param cstr the c-string
//! \param len the length of the \c str_t
//! \return a new \c str_t
str_t strl(const char*, usize_t);

//! \fn str_t strr(const char *cstr, usize_t len);
//! \brief create a \c str_t containing only the last \c len chars of \c cstr
//! \param cstr the c-string
//! \param len the length of the \c str_t
//! \return a new \c str_t
str_t strr(const char*, usize_t);

//! \fn str_t str(const char *cstr);
//! \brief create a \c str_t containing the entirety of \c cstr
//! \param cstr the c-string
//! \return a new \c str_t
str_t str(const char*);

#endif /* LIBMY_STR_H */
