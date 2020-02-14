/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** array
*/

#include "my/json.h"
#include "my/cstr.h"
#include "my/my.h"

static opt_i32_t get_array_length(const char *json_str, int i)
{
    i32_t exp_closing = 1;
    i32_t counted_index = 1;

    if (json_str[i] == ']')
        return ((opt_i32_t)SOME(0));
    for (; json_str[i] != '\0'; i++) {
        if (json_str[i] == ']' && exp_closing == 1)
            return ((opt_i32_t)SOME(counted_index));
        else if (json_str[i] == ']')
            exp_closing--;
        if (json_str[i] == '[')
            exp_closing++;
        if (json_str[i] == ',')
            counted_index++; 
    }
    return ((opt_i32_t)NONE);
} 

static json_t *init_array(opt_i32_t array_length)
{
    json_t *obj = NULL;

    obj = json_create_array();
    obj->u.array.len = array_length.v;
    obj->u.array.data = my_malloc(sizeof(json_t*) * obj->u.array.len);
    return (obj->u.array.data ? obj : NULL);
}

json_t *json_parse_array(const char *json_str, int *i)
{
    json_t *obj = NULL;
    opt_i32_t arr_len;

    if (json_str[(*i)++] != '[')
        return (NULL);
    arr_len = get_array_length(json_str, *i);
    if (!arr_len.is_some || !(obj = init_array(arr_len)))
        return (NULL);
    for (int j = 0; j < arr_len.v ; j++) {
        obj->u.array.data[j] = json_parse_entity(json_str, i);
        if (json_str[*i] == ',')
            (*i)++;
    }      
    if (json_str[*i] == '\0')
        return (NULL);
    (*i)++;
    return (obj);
}