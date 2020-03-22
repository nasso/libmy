/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** 16 bit endianness conversions
*/

#include "my/mem.h"

u16_t u16_ne_to_be(u16_t ne)
{
    if (my_is_big_endian())
        return (ne);
    return (u16_swap_endian(ne));
}

u16_t u16_ne_to_le(u16_t ne)
{
    if (my_is_little_endian())
        return (ne);
    return (u16_swap_endian(ne));
}
