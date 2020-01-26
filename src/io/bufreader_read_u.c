/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Buffered reader
*/

#include "my/my.h"
#include "my/io.h"

int bufreader_read_u8(bufreader_t *self, u8_t *value)
{
    return (bufreader_read(self, value, sizeof(u8_t)));
}

int bufreader_read_u16(bufreader_t *self, u16_t *value)
{
    return (bufreader_read(self, value, sizeof(u16_t)));
}

int bufreader_read_u32(bufreader_t *self, u32_t *value)
{
    return (bufreader_read(self, value, sizeof(u32_t)));
}

int bufreader_read_u64(bufreader_t *self, u64_t *value)
{
    return (bufreader_read(self, value, sizeof(u64_t)));
}

int bufreader_read_usize(bufreader_t *self, usize_t *value)
{
    return (bufreader_read(self, value, sizeof(usize_t)));
}
