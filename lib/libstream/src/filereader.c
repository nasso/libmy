/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** File reader using a buffered reader
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "filereader.h"
#include "bufreader.h"

static int filereader_read_cb(int *fdptr, char *buffer, int n)
{
    return (read(*fdptr, buffer, n));
}

static void filereader_free_cb(int *fdptr)
{
    if (*fdptr >= 3)
        close(*fdptr);
    free(fdptr);
}

bufreader_t *filereader_from(int fd, int buf_size)
{
    int *fdptr = malloc(sizeof(int));
    bufreader_t *br = bufreader_new(buf_size);

    *fdptr = fd;
    br->user_data = fdptr;
    br->read_cb = (bufreader_read_cb*) &filereader_read_cb;
    br->free_cb = (bufreader_free_cb*) &filereader_free_cb;
    return (br);
}

bufreader_t *filereader_open(char const *path, int buf_size)
{
    int fd = open(path, O_RDONLY, buf_size);

    if (fd < 0)
        return (NULL);
    return (filereader_from(fd, buf_size));
}
