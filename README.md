# libmy

Personal library for the my [EPITECH](https://www.epitech.eu) projects.

## Demo

```c
#include "my/my.h"
#include "my/collections/hash_map.h"

// Demonstrate the use of the OPTION(T) type
static opt_f64_t safe_div(f64_t a, f64_t b)
{
    if (b == 0)
        return ((opt_f64_t) NONE);
    return ((opt_f64_t) SOME(a / b));
}

// Put arguments in a hash map
int main(int ac, char **av) {
    hash_map_t *args = hash_map_new();
    char *foo = NULL;

    for (usize_t i = 1; i + 1 < ac; i += 2)
        hash_map_insert(args, av[i], av[i + 1]);
    foo = hash_map_get(args, "foo");
    if (foo)
        my_printf("foo: %s\n", foo);
    hash_map_destroy(args);
    return (0);
}
```

## Features

### Obvious primitive data type definitions:
- `[iu](8|16|32|64|size)_t`: integer data types (`u8_t`, `i32_t`, ...)
- `f(32|64)_t`: floating point data types (e.g. an `f32_t` is just a `float`)
- `<primitive>_(min|max)`: `min` and `max` functions for any primitive

### Additionnal useful generic data types:
- `OPTION(T)`: similar to Rust's `Option<T>` or Haskell's `Maybe T`
- `RESULT(T, E)`: similar to Rust's `Result<T, E>`
- `opt_<primitive>_t`: `OPTION(T)` for all primitives!!

### Wrappers for standard functions to avoid `"banned function used"` errors:
- `my_malloc`, `my_free` and `my_calloc`
- `my_memcpy`, `my_memmove` and `my_memset`
- `my_open` and `my_close`
- `my_read` and `my_write`

### General purpose collections:
- `vector_t`: a continuous growable array (copies the elements' data)
- `list_t`: circular doubly linked list (stores pointers to elements)
- `hash_map_t`: an hash table implementation (stores pointers to elements)

### Formatting utilities:
- `my_printf`: yeah (no support for floating point data types yet tho)
- `my_format`: format a string to a newly allocated `char *`

### Buffered IO helpers:
- `bufreader_t`: abstract buffered input stream
- `bufwriter_t`: abstract buffered output stream
- `filereader_t`: implementation of `bufreader_t` around a file descriptor
- `filewriter_t`: implementation of `bufwriter_t` around a file descriptor
