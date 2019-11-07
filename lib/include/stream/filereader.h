/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** File reader using a buffered reader
*/

#ifndef FILEREADER_H
#define FILEREADER_H

#include "bufreader.h"

bufreader_t *filereader_from(int fd, int buf_size);
bufreader_t *filereader_open(char const *path, int buf_size);

#endif /* FILEREADER_H */
