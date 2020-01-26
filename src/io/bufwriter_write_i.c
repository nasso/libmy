/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Buffered writer
*/

#include "my/my.h"
#include "my/io.h"

int bufwriter_write_i8(bufwriter_t *self, i8_t value)
{
    return (bufwriter_write(self, &value, sizeof(i8_t)));
}

int bufwriter_write_i16(bufwriter_t *self, i16_t value)
{
    return (bufwriter_write(self, &value, sizeof(i16_t)));
}

int bufwriter_write_i32(bufwriter_t *self, i32_t value)
{
    return (bufwriter_write(self, &value, sizeof(i32_t)));
}

int bufwriter_write_i64(bufwriter_t *self, i64_t value)
{
    return (bufwriter_write(self, &value, sizeof(i64_t)));
}

int bufwriter_write_isize(bufwriter_t *self, isize_t value)
{
    return (bufwriter_write(self, &value, sizeof(isize_t)));
}
