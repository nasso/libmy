/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Private functions used by the linked list implementation
*/

#ifndef LIBMY_COLLECTIONS_LIST_PRIV_H
#define LIBMY_COLLECTIONS_LIST_PRIV_H

#include <stddef.h>
#include "list.h"

list_node_t *list__create_node(void*);
list_node_t *list__get_nth_node(list_node_t*, size_t);
void *list__destroy_node(list_node_t*);
void list__insert_before(list_node_t*, list_node_t*);
void list__insert_after(list_node_t*, list_node_t*);

#endif /* LIBMY_COLLECTIONS_LIST_PRIV_H */
