/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** Buffered writer
*/

#ifndef BUFWRITER_H
#define BUFWRITER_H

#include "my/my.h"

typedef int (bufwriter_write_cb)(void*, const void*, int);
typedef void (bufwriter_free_cb)(void*);

typedef struct bufwriter {
    u8_t *buffer;
    int buffer_size;
    int cursor;
    int ended;
    void *user_data;
    bufwriter_write_cb *write_cb;
    bufwriter_free_cb *free_cb;
} bufwriter_t;

bufwriter_t *bufwriter_new(int buf_size);
void bufwriter_free(bufwriter_t*);
int bufwriter_putchar(bufwriter_t*, char);
int bufwriter_write(bufwriter_t*, const void*, int);
int bufwriter_flush(bufwriter_t*);
int bufwriter_write_u8(bufwriter_t*, u8_t);
int bufwriter_write_u16(bufwriter_t*, u16_t);
int bufwriter_write_u32(bufwriter_t*, u32_t);
int bufwriter_write_u64(bufwriter_t*, u64_t);
int bufwriter_write_usize(bufwriter_t*, usize_t);
int bufwriter_write_i8(bufwriter_t*, i8_t);
int bufwriter_write_i16(bufwriter_t*, i16_t);
int bufwriter_write_i32(bufwriter_t*, i32_t);
int bufwriter_write_i64(bufwriter_t*, i64_t);
int bufwriter_write_isize(bufwriter_t*, isize_t);

#endif /* BUFWRITER_H */
