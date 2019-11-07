/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** Buffered writer
*/

#include <stdlib.h>
#include "bufwriter.h"

bufwriter_t *bufwriter_new(int buf_size)
{
    bufwriter_t *bw = malloc(sizeof(bufwriter_t));

    if (bw == NULL)
        return (NULL);
    bw->buffer = malloc(sizeof(char) * buf_size);
    if (bw->buffer == NULL) {
        free(bw);
        return (NULL);
    }
    bw->buffer_size = buf_size;
    bw->cursor = 0;
    bw->ended = 0;
    bw->user_data = NULL;
    bw->write_cb = NULL;
    bw->free_cb = NULL;
    return (bw);
}

void bufwriter_free(bufwriter_t *bw)
{
    bufwriter_flush(bw);
    if (bw->free_cb)
        bw->free_cb(bw);
}

int bufwriter_flush(bufwriter_t *bw)
{
    int bytes_written = 0;

    if (bw->cursor > 0)
        bytes_written = bw->write_cb(bw->user_data, bw->buffer, bw->cursor);
    bw->cursor = 0;
    return (bytes_written);
}

int bufwriter_putchar(bufwriter_t *bw, char c)
{
    bw->cursor++;
    if (bw->cursor == bw->buffer_size)
        bufwriter_flush(bw);
    bw->buffer[bw->cursor] = c;
    return (1);
}

int bufwriter_write(bufwriter_t *bw, char const *buffer, int n)
{
    int bytes_written = n;

    if (bw->cursor + n >= bw->buffer_size) {
        bufwriter_flush(bw);
        bytes_written = bw->write_cb(bw->user_data, buffer, n);
    } else {
        for (int i = 0; i < n; i++)
            bw->buffer[bw->cursor + i] = buffer[i];
        bw->cursor += n;
    }
    return (bytes_written);
}
