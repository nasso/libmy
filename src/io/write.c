/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_write
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "io.h"

isize_t my_write(int fd, const void *buf, usize_t count)
{
#if defined(MY_ALLOW_FUN_WRITE)
    return (write(fd, buf, (size_t) count));
#else
    (void)(fd);
    (void)(buf);
    (void)(count);
    return (-1);
#endif
}
