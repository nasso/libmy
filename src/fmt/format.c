/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_format implementation
*/

#include <stddef.h>
#include <stdarg.h>
#include "my/my.h"
#include "my/io.h"

static const int BUFFER_SIZE = 2048;

struct string_buffer {
    char *str;
    usize_t len;
    usize_t cursor;
};

static OPT(usize) write_cb(void *ptr, const void *buffer, usize_t n)
{
    struct string_buffer *dest = ptr;
    usize_t new_strlen = dest->len + n;
    char *new_str = my_malloc((new_strlen + 1) * sizeof(char));

    for (usize_t i = 0; i < dest->len; i++)
        new_str[i] = dest->str[i];
    for (usize_t i = 0; i < n; i++)
        new_str[dest->len + i] = ((const char*) buffer)[i];
    new_str[new_strlen] = '\0';
    my_free(dest->str);
    dest->str = new_str;
    dest->len = new_strlen;
    return (SOME(usize, n));
}

static struct string_buffer *init_buf(void)
{
    struct string_buffer *buf = my_malloc(sizeof(struct string_buffer));

    if (buf == NULL)
        return (NULL);
    buf->str = my_malloc(sizeof(char));
    buf->str[0] = '\0';
    buf->len = 0;
    buf->cursor = 0;
    return (buf);
}

static bufwriter_t *init_bufwriter(struct string_buffer *strbuf)
{
    bufwriter_t *bw = bufwriter_new(BUFFER_SIZE);

    if (bw == NULL)
        return (NULL);
    bw->user_data = strbuf;
    bw->write_cb = &write_cb;
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
