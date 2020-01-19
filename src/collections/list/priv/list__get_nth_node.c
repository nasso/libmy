/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Private linked list functions implementation
*/

#include <stdlib.h>
#include "my.h"
#include "collections/list.h"
#include "collections/list_priv.h"

list_node_t *list__get_nth_node(list_node_t *head, size_t n)
{
    list_node_t *node = head;

    while (head && n--)
        node = node->next;
    return (node);
}