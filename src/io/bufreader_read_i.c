/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Buffered reader
*/

#include "my/my.h"
#include "my/io.h"

int bufreader_read_i8(bufreader_t *self, i8_t *value)
{
    return (bufreader_read(self, value, sizeof(i8_t)));
}

int bufreader_read_i16(bufreader_t *self, i16_t *value)
{
    return (bufreader_read(self, value, sizeof(i16_t)));
}

int bufreader_read_i32(bufreader_t *self, i32_t *value)
{
    return (bufreader_read(self, value, sizeof(i32_t)));
}

int bufreader_read_i64(bufreader_t *self, i64_t *value)
{
    return (bufreader_read(self, value, sizeof(i64_t)));
}

int bufreader_read_isize(bufreader_t *self, isize_t *value)
{
    return (bufreader_read(self, value, sizeof(isize_t)));
}
