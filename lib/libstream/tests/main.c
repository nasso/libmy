/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** Main file to do random testing
*/

#include <stdlib.h>
#include <stdio.h>
#include "stream.h"

static void check_file_stream(void *data, char const *filename)
{
    if (data != NULL)
        return;
    printf("Couldn't open %s\n", filename);
    exit(1);
}

int main(int ac, char **av)
{
    bufreader_t *reader = NULL;
    bufwriter_t *writer = NULL;
    int read_bytes = 0;
    char buf[456];

    if (ac == 1) {
        printf("USAGE: %s <source> <copy>\n", av[0]);
        return (1);
    }
    reader = filereader_open(av[1], 242);
    writer = filewriter_open(av[2], 132);
    check_file_stream(reader, av[1]);
    check_file_stream(writer, av[2]);
    while (!reader->ended) {
        read_bytes = bufreader_read(reader, buf, 456);
        bufwriter_write(writer, buf, read_bytes);
    }
    bufreader_free(reader);
    bufwriter_free(writer);
    return (0);
}
