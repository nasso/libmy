/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Circular doubly-linked list data structure
*/

#ifndef LIBMY_COLLECTIONS_LIST_H
#define LIBMY_COLLECTIONS_LIST_H

#include <stdbool.h>
#include <stdarg.h>
#include "types.h"

typedef int (list_iter_fn_t)(void *user_data, void *element);

typedef struct list_node {
    struct list_node *next;
    struct list_node *previous;
    void *val;
} list_node_t;

typedef struct {
    struct list_node *head;
    usize_t len;
} list_t;

list_t *list_new(void);
list_t *list_from(usize_t, ...);
list_t *list_from_var(usize_t, va_list);
list_t *list_from_arr(usize_t, void**);
void list_destroy(list_t*);
void list_destroy_with(list_t*, list_iter_fn_t*, void*);
bool list_push_front(list_t*, void*);
bool list_push_back(list_t*, void*);
bool list_insert(list_t*, usize_t, void*);
bool list_set(list_t*, usize_t, void*);
void *list_pop_front(list_t*);
void *list_pop_back(list_t*);
void *list_remove(list_t*, usize_t);
void *list_remove_element(list_t*, void*, list_iter_fn_t*);
void list_clear(list_t*);
void list_clear_with(list_t*, list_iter_fn_t*, void*);
void *list_get(const list_t*, usize_t);
void *list_find(list_t*, void*);
void *list_find_with(list_t*, list_iter_fn_t*, void*);
int list_for_each(list_t*, list_iter_fn_t*, void*);

#endif /* LIBMY_COLLECTIONS_LIST_H */
