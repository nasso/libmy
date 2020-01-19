/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Circular doubly-linked list data structure
*/

#ifndef LIBMY_COLLECTIONS_LIST_H
#define LIBMY_COLLECTIONS_LIST_H

#include <stddef.h>
#include <stdarg.h>

typedef int (list_for_each_fn_t)(void *user_data, void *element);
typedef int (list_cmp_fn_t)(const void*, const void*);
typedef int (list_find_fn_t)(void *user_data, void *element);

typedef struct list_node {
    struct list_node *next;
    struct list_node *previous;
    void *val;
} list_node_t;

typedef struct {
    struct list_node *head;
    size_t len;
} list_t;

list_t *list_new(void);
list_t *list_from(size_t, ...);
list_t *list_from_var(size_t, va_list);
list_t *list_from_arr(size_t, void**);
void list_destroy(list_t*);
void list_destroy_with(list_t*, list_for_each_fn_t*, void*);
void list_for_each(list_t*, list_for_each_fn_t*, void*);
void list_clear(list_t*);
void list_clear_with(list_t*, list_for_each_fn_t*, void*);
void *list_pop_front(list_t*);
void *list_pop_back(list_t*);
int list_push_front(list_t*, void*);
int list_push_back(list_t*, void*);
void *list_get(const list_t*, size_t);
int list_set(list_t*, size_t, void*);
void *list_remove(list_t*, size_t);
int list_insert(list_t*, size_t, void*);
void *list_remove_element(list_t*, const void*, list_cmp_fn_t*);
void *list_find(list_t*, list_find_fn_t*, void*);

#endif /* LIBMY_COLLECTIONS_LIST_H */
