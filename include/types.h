/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Primitive typedefs
*/

#ifndef LIBMY_TYPES_H
#define LIBMY_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "option.h"

typedef uint8_t u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef uint64_t u64_t;
typedef uintptr_t usize_t;
typedef int8_t i8_t;
typedef int16_t i16_t;
typedef int32_t i32_t;
typedef int64_t i64_t;
typedef intptr_t isize_t;
typedef float f32_t;
typedef double f64_t;
typedef OPTION(bool) opt_bool_t;
typedef OPTION(u8_t) opt_u8_t;
typedef OPTION(u16_t) opt_u16_t;
typedef OPTION(u32_t) opt_u32_t;
typedef OPTION(u64_t) opt_u64_t;
typedef OPTION(usize_t) opt_usize_t;
typedef OPTION(i8_t) opt_i8_t;
typedef OPTION(i16_t) opt_i16_t;
typedef OPTION(i32_t) opt_i32_t;
typedef OPTION(i64_t) opt_i64_t;
typedef OPTION(isize_t) opt_isize_t;
typedef OPTION(f32_t) opt_f32_t;
typedef OPTION(f64_t) opt_f64_t;

#endif /* LIBMY_TYPES_H */
