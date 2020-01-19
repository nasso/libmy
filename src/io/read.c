/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_read
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "io.h"

isize_t my_read(int fd, void *buf, usize_t count)
{
#if defined(MY_ALLOW_FUN_READ)
    return (read(fd, buf, (size_t) count));
#else
    (void)(fd);
    (void)(buf);
    (void)(count);
    return (-1);
#endif
}
