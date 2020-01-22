/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "collections/list.h"
#include "collections/list_priv.h"

void *list_remove_element(list_t *self, void *element, list_iter_fn_t *fn)
{
    void *val = NULL;
    list_node_t *head = self->head;
    list_node_t *head_next = self->len <= 1 ? NULL : self->head->next;
    list_node_t *node = head;

    if (node == NULL)
        return (NULL);
    for (size_t i = 0; i < self->len; i++) {
        if (fn ? !fn(element, node->val) : (element == node->val)) {
            val = list__destroy_node(node);
            self->head = node == head ? head_next : head;
            self->len--;
            return (val);
        }
        node = node->next;
    }
    return (NULL);
}
