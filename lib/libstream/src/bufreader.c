/*
** EPITECH PROJECT, 2019
** CPool_finalstumper_2019
** File description:
** Bufreader implementation
*/

#include <stdlib.h>
#include <unistd.h>
#include "bufreader.h"

static void read_more(bufreader_t *br)
{
    br->bytes_left = br->read_cb(br->user_data, br->buffer, br->buffer_size);
    br->cursor = 0;
    br->ended = br->bytes_left == 0;
}

bufreader_t *bufreader_new(int buf_size)
{
    bufreader_t *br = malloc(sizeof(bufreader_t));

    if (br == NULL)
        return (NULL);
    br->buffer = malloc(sizeof(char) * buf_size);
    if (br->buffer == NULL)
        return (NULL);
    br->buffer_size = buf_size;
    br->bytes_left = 0;
    br->cursor = 0;
    br->ended = 0;
    br->user_data = NULL;
    br->read_cb = NULL;
    br->free_cb = NULL;
    return (br);
}

void bufreader_free(bufreader_t *br)
{
    if (br->free_cb)
        br->free_cb(br->user_data);
    free(br->buffer);
    free(br);
}

char bufreader_getchar(bufreader_t *br)
{
    if (br->bytes_left == 0)
        read_more(br);
    if (br->ended)
        return ('\0');
    br->bytes_left--;
    br->cursor++;
    return (br->buffer[br->cursor - 1]);
}

int bufreader_read(bufreader_t *br, char *buffer, int n)
{
    int i = 0;
    int read_bytes = 0;

    if (br->ended)
        return (0);
    for (; i < n && i < br->bytes_left; i++)
        buffer[i] = br->buffer[br->cursor + i];
    br->bytes_left = 0;
    read_bytes = i;
    if (n - i > 0)
        read_bytes += br->read_cb(br->user_data, buffer, n - i);
    br->ended = read_bytes == 0;
    return (read_bytes);
}
