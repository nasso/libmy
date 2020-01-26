/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** Buffered reader
*/

#ifndef BUFREADER_H
#define BUFREADER_H

#include "my/my.h"

typedef int (bufreader_read_cb)(void*, void*, int);
typedef void (bufreader_free_cb)(void*);

typedef struct bufreader {
    u8_t *buffer;
    int buffer_size;
    int bytes_left;
    int cursor;
    int ended;
    void *user_data;
    bufreader_read_cb *read_cb;
    bufreader_free_cb *free_cb;
} bufreader_t;

bufreader_t *bufreader_new(int buf_size);
void bufreader_free(bufreader_t*);
char bufreader_getchar(bufreader_t*);
char bufreader_peekchar(bufreader_t*);
int bufreader_read(bufreader_t*, void*, int);
int bufreader_read_u8(bufreader_t*, u8_t*);
int bufreader_read_u16(bufreader_t*, u16_t*);
int bufreader_read_u32(bufreader_t*, u32_t*);
int bufreader_read_u64(bufreader_t*, u64_t*);
int bufreader_read_usize(bufreader_t*, usize_t*);
int bufreader_read_i8(bufreader_t*, i8_t*);
int bufreader_read_i16(bufreader_t*, i16_t*);
int bufreader_read_i32(bufreader_t*, i32_t*);
int bufreader_read_i64(bufreader_t*, i64_t*);
int bufreader_read_isize(bufreader_t*, isize_t*);

#endif /* BUFREADER_H */
