/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "collections/list.h"
#include "collections/list_priv.h"

void *list_remove_element(list_t *self, const void *elem, list_cmp_fn_t *cmp)
{
    void *val = NULL;
    list_node_t *head = self->head;
    list_node_t *head_next = self->len <= 1 ? NULL : self->head->next;
    list_node_t *node = head;

    if (node == NULL)
        return (NULL);
    for (size_t i = 0; i < self->len; i++) {
        if (elem == node->val || (cmp != NULL && cmp(elem, node->val) == 0)) {
            val = list__destroy_node(node);
            self->head = node == head ? head_next : head;
            self->len--;
            return (val);
        }
        node = node->next;
    }
    return (NULL);
}
