/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** Buffered writer
*/

#ifndef BUFWRITER_H
#define BUFWRITER_H

typedef int (bufwriter_write_cb)(void*, char const*, int);
typedef void (bufwriter_free_cb)(void*);

typedef struct bufwriter {
    char *buffer;
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
int bufwriter_write(bufwriter_t*, char const*, int);
int bufwriter_flush(bufwriter_t*);

#endif /* BUFWRITER_H */
