/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** array
*/

#include "my/json.h"
#include "my/cstr.h"
#include "my/my.h"

char *get_var_name(const char *json_str, int *i)
{
    int ret_length = 0;
    char *ret_str = NULL;
    int j = 0;
    int k = (*i) + 1;

    if (json_str[(*i)] == '\"')
        (*i)++;
    for (; json_str[k] != '\0' && json_str[k] != '\"'; k++) 
        ret_length++;
    if (!(ret_str = my_malloc(sizeof(char) * ret_length)))
        return (NULL);
    for (; j < ret_length; j++)
        ret_str[j] = json_str[(*i)++];   
    ret_str[j] = '\0';
    if (json_str[(*i)] == '\"')
        (*i)++;
    return (ret_str);
}

/*
    TODO: Do we need to free (obj_name) ?
*/
json_t *json_parse_object(const char *json_str, int *i)
{
    json_t *obj = NULL;
    char *parsed_str = NULL;
    char *obj_name = NULL;

    if (json_str[(*i)++] != '{')
        return (NULL);
    obj = json_create_object();
    for (; json_str[*i] != '\0' && json_str[*i] != '}';) {
        if (!(obj_name = get_var_name(json_str, i)))
            return (NULL);
        (*i)++;
        json_object_set(obj, obj_name, json_parse_entity(json_str, i));
        if (json_str[*i] != ',' && json_str[*i] != '}')
            return (NULL);
        (*i)++;
    }
    if (json_str[(*i) - 1] != '}') {
        json_destroy(obj);
        return (NULL);
    }  
    return (obj);
}