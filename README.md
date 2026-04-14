# libft

[![42](https://img.shields.io/badge/42-Project-blue)](https://42.fr)
[![C](https://img.shields.io/badge/Language-C-green)](https://en.wikipedia.org/wiki/C_(programming_language))

> A custom C library used as the foundation for all subsequent 42 School projects.

## Overview

`libft` is a 42 School Rank 0 project. The goal is to re-implement a set of standard C library functions from scratch, then extend the library with additional utilities needed across later projects.

## Original vs Extended

This library started as the mandatory 42 libft submission and was progressively extended while working on later projects (ft_printf, get_next_line, push_swap, pipex, minishell...).

> Original submission: tag [`v1.0-original`](../../releases/tag/v1.0-original)
> Current extended version: tag [`v2.0-extended`](../../releases/tag/v2.0-extended)

### Original 42 libft (mandatory + bonus)

| Category | Functions |
|----------|-----------|
| Libc reimplementation | `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` `ft_strlen` `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp` `ft_strlcpy` `ft_strlcat` `ft_tolower` `ft_toupper` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_strnstr` `ft_atoi` `ft_calloc` `ft_strdup` |
| Additional functions | `ft_substr` `ft_strjoin` `ft_strtrim` `ft_split` `ft_itoa` `ft_strmapi` `ft_striteri` `ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd` |
| Bonus (linked lists) | `ft_lstnew` `ft_lstadd_front` `ft_lstadd_back` `ft_lstsize` `ft_lstlast` `ft_lstdelone` `ft_lstclear` `ft_lstiter` `ft_lstmap` |

### Added functions (beyond the project)

| Function | Reason added |
|----------|-------------|
| `ft_isspace` | Needed for parsing in multiple projects |
| `ft_strcpy` `ft_strcmp` | Common string ops missing from original |
| `ft_strjoin2` | `strjoin` variant with memory management flags (1=free s1, 2=free s2, 3=both) |
| `ft_printf` `ft_printf_fd` | Integrated from ft_printf project, with custom `%a/%A/%t/%T` array specifiers |
| `get_next_line` (bonus) | Integrated from get_next_line project |
| `ft_arraylen` `ft_free_array` `ft_rm_from_array` | Array management for projects using `char **` |
| `ft_swap` | Utility used in sorting projects |
| `ft_realloc` `ft_realloc_and_clear` | Dynamic memory resizing |

## Usage

```bash
make
```

Produces `libft.a`.

```bash
cc -Wall -Wextra -Werror your_file.c -L. -lft -I./include
```

### Example

```c
#include "include/libft.h"

int main(void)
{
    char *sub = ft_substr("Hello, World!", 0, 5);
    ft_printf("%s\n", sub);
    free(sub);
    return (0);
}
```

## Project structure

```
libft/
├── include/
│   └── libft.h
├── src/
│   └── ft_*.c
└── Makefile
```

## Make targets

| Target | Description |
|--------|-------------|
| `make` | Build the library |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and library |
| `make re` | Rebuild from scratch |
| `make norm` | Run norminette |

## Author

**Laher Maciel**
- GitHub: [@LaherMaciel](https://github.com/LaherMaciel)
- 42 Login: lawences
