/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_calloc
*/

#include <stdlib.h>
#include "my.h"

void *my_calloc(usize_t nmemb, usize_t size)
{
    void *buf = NULL;

    (void)(nmemb);
    (void)(size);
#if defined(MY_ALLOW_FUN_CALLOC)
    buf = calloc(nmemb, size);
#elif defined(MY_ALLOW_FUN_MALLOC)
    buf = malloc(nmemb * size);
    if (buf != NULL)
        my_memset(buf, 0, nmemb * size);
#endif
    return (buf);
}
