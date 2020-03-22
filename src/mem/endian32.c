/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** 32 bit endianness conversions
*/

#include "my/mem.h"

u32_t u32_ne_to_be(u32_t ne)
{
    if (my_is_big_endian())
        return (ne);
    return (u32_swap_endian(ne));
}

u32_t u32_ne_to_le(u32_t ne)
{
    if (my_is_little_endian())
        return (ne);
    return (u32_swap_endian(ne));
}
