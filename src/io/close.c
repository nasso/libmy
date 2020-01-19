/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_close
*/

#include <unistd.h>
#include "my.h"
#include "io.h"

int my_close(int fd)
{
#if defined(MY_ALLOW_FUN_CLOSE)
    return (close(fd));
#else
    (void)(fd);
    return (-1);
#endif
}
