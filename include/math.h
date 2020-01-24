/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Maths utils
*/

#ifndef LIBMY_MATH_H
#define LIBMY_MATH_H

#define MY_MAX(A, B) ((A) < (B) ? (B) : (A))
#define MY_MIN(A, B) ((A) > (B) ? (B) : (A))

#include "my/types.h"

#define IMPL_MAX(T) \
    static inline T my_max_##T(T a, T b) { return (a < b ? b : a); }
#define IMPL_MIN(T) \
    static inline T my_min_##T(T a, T b) { return (a > b ? b : a); }
#define IMPL_MIN_AND_MAX(T) IMPL_MIN(T) IMPL_MAX(T)

IMPL_MIN_AND_MAX(u8_t)
IMPL_MIN_AND_MAX(u16_t)
IMPL_MIN_AND_MAX(u32_t)
IMPL_MIN_AND_MAX(u64_t)
IMPL_MIN_AND_MAX(i8_t)
IMPL_MIN_AND_MAX(i16_t)
IMPL_MIN_AND_MAX(i32_t)
IMPL_MIN_AND_MAX(i64_t)
IMPL_MIN_AND_MAX(f32_t)
IMPL_MIN_AND_MAX(f64_t)
IMPL_MIN_AND_MAX(usize_t)
IMPL_MIN_AND_MAX(isize_t)

#undef IMPL_MAX
#undef IMPL_MIN
#undef IMPL_MIN_AND_MAX

#endif /* LIBMY_MATH_H */
