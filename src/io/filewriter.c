/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** File writer using a buffered writer
*/

#include <stddef.h>
#include <fcntl.h>
#include "my/my.h"
#include "my/io.h"

static int filewriter_write_cb(int *fdptr, char *buffer, int n)
{
    return (my_write(*fdptr, buffer, n));
}

static void filewriter_free_cb(int *fdptr)
{
    my_free(fdptr);
}

static void filewriter_close_and_free(int *fdptr)
{
    if (fdptr)
        my_close(*fdptr);
    my_free(fdptr);
}

bufwriter_t *filewriter_from(int fd, int buf_size)
{
    int *fdptr = my_malloc(sizeof(int));
    bufwriter_t *br = NULL;

    if (fdptr == NULL)
        return (NULL);
    br = bufwriter_new(buf_size);
    if (br == NULL) {
        my_free(fdptr);
        return (NULL);
    }
    *fdptr = fd;
    br->user_data = fdptr;
    br->write_cb = (bufwriter_write_cb*) &filewriter_write_cb;
    br->free_cb = (bufwriter_free_cb*) &filewriter_free_cb;
    return (br);
}

bufwriter_t *filewriter_open(char const *path, int buf_size)
{
    int fd = my_open(path, O_WRONLY);
    bufwriter_t *self = NULL;

    if (fd < 0)
        return (NULL);
    self = filewriter_from(fd, buf_size);
    if (self)
        self->free_cb = (bufwriter_free_cb*) &filewriter_close_and_free;
    return (self);
}
