/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** File reader using a buffered reader
*/

#ifndef FILEREADER_H
#define FILEREADER_H

#include "my/io/bufreader.h"

bufreader_t *filereader_from(fd_t fd, usize_t buf_size);
bufreader_t *filereader_open(char const *path, usize_t buf_size);

#endif /* FILEREADER_H */
