/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** File writer using a buffered writer
*/

#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "my/io/bufwriter.h"

bufwriter_t *filewriter_from(int fd, int buf_size);
bufwriter_t *filewriter_open(char const *path, int buf_size);

#endif /* FILEWRITER_H */
