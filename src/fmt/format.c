/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_format implementation
*/

#include <stddef.h>
#include <stdarg.h>
#include "my.h"
#include "io.h"

static const int BUFFER_SIZE = 2048;

struct string_buffer {
    char *str;
    int strlen;
    int cursor;
};

static int write_cb(struct string_buffer *dest, char const *buffer, int n)
{
    int new_strlen = dest->strlen + n;
    char *new_str = my_malloc(sizeof(char) * (new_strlen + 1));

    for (int i = 0; i < dest->strlen; i++)
        new_str[i] = dest->str[i];
    for (int i = 0; i < n; i++)
        new_str[dest->strlen + i] = buffer[i];
    new_str[new_strlen] = '\0';
    my_free(dest->str);
    dest->str = new_str;
    dest->strlen = new_strlen;
    return (n);
}

static struct string_buffer *init_buf(void)
{
    struct string_buffer *buf = my_malloc(sizeof(struct string_buffer));

    if (buf == NULL)
        return (NULL);
    buf->str = my_malloc(sizeof(char));
    buf->str[0] = '\0';
    buf->strlen = 0;
    buf->cursor = 0;
    return (buf);
}

static bufwriter_t *init_bufwriter(struct string_buffer *strbuf)
{
    bufwriter_t *bw = bufwriter_new(BUFFER_SIZE);

    if (bw == NULL)
        return (NULL);
    bw->user_data = strbuf;
    bw->write_cb = (bufwriter_write_cb*) &write_cb;
    bw->free_cb = NULL;
    return (bw);
}

char *my_format(char const *fmt, ...)
{
    va_list ap;
    char *str = NULL;
    bufwriter_t *bw = NULL;
    struct string_buffer *buf = init_buf();

    if (buf == NULL)
        return (NULL);
    bw = init_bufwriter(buf);
    if (bw == NULL) {
        my_free(buf->str);
        my_free(buf);
        return (NULL);
    }
    va_start(ap, fmt);
    my_vbufprintf(bw, fmt, ap);
    va_end(ap);
    bufwriter_free(bw);
    str = buf->str;
    my_free(buf);
    return (str);
}
