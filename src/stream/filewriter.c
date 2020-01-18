/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** File writer using a buffered writer
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "stream/filewriter.h"
#include "stream/bufwriter.h"

static int filewriter_write_cb(int *fdptr, char *buffer, int n)
{
    return (write(*fdptr, buffer, n));
}

static void filewriter_free_cb(int *fdptr)
{
    if (*fdptr >= 3)
        close(*fdptr);
    free(fdptr);
}

bufwriter_t *filewriter_from(int fd, int buf_size)
{
    int *fdptr = malloc(sizeof(int));
    bufwriter_t *br = bufwriter_new(buf_size);

    *fdptr = fd;
    br->user_data = fdptr;
    br->write_cb = (bufwriter_write_cb*) &filewriter_write_cb;
    br->free_cb = (bufwriter_free_cb*) &filewriter_free_cb;
    return (br);
}

bufwriter_t *filewriter_open(char const *path, int buf_size)
{
    int fd = open(path, O_WRONLY, buf_size);

    if (fd < 0)
        return (NULL);
    return (filewriter_from(fd, buf_size));
}
