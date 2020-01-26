/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** File reader using a buffered reader
*/

#include <stddef.h>
#include <fcntl.h>
#include "my/my.h"
#include "my/io.h"

static int filereader_read_cb(int *fdptr, char *buffer, int n)
{
    return (my_read(*fdptr, buffer, n));
}

static void filereader_free_cb(int *fdptr)
{
    my_free(fdptr);
}

static void filereader_close_and_free_cb(int *fdptr)
{
    if (fdptr)
        my_close(*fdptr);
    my_free(fdptr);
}

bufreader_t *filereader_from(int fd, int buf_size)
{
    int *fdptr = my_malloc(sizeof(int));
    bufreader_t *br = bufreader_new(buf_size);

    *fdptr = fd;
    br->user_data = fdptr;
    br->read_cb = (bufreader_read_cb*) &filereader_read_cb;
    br->free_cb = (bufreader_free_cb*) &filereader_free_cb;
    return (br);
}

bufreader_t *filereader_open(char const *path, int buf_size)
{
    int fd = my_open(path, O_RDONLY);
    bufreader_t *self = NULL;

    if (fd < 0)
        return (NULL);
    self = filereader_from(fd, buf_size);
    if (self)
        self->free_cb = (bufreader_free_cb*) &filereader_close_and_free_cb;
    return (self);
}
