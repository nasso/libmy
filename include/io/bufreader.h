/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** Buffered reader
*/

#ifndef BUFREADER_H
#define BUFREADER_H

typedef int (bufreader_read_cb)(void*, char*, int);
typedef void (bufreader_free_cb)(void*);

typedef struct bufreader {
    char *buffer;
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
int bufreader_read(bufreader_t*, char*, int);

#endif /* BUFREADER_H */
