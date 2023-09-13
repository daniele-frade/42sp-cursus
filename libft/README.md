# Libft

This project is the first project as a student at 42. It is about coding a `C library`. It will contain a lot of **general purpose functions** your programs will rely upon.
<br>
<br>

## ✅ Mandatory part

- To begin, you must redo a set of functions from the `libc`. Your functions will have the same prototypes and implement the same behaviors as the originals. They must comply with the way they are defined in their manual.

- In the second part, you must develop a set of functions that are either not in the `libc`, or that are part of it but in a different form.


### Libc Functions

| Function | Description |
| :------: | :---------: |
| [`ft_atoi`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_atoi.c) | The `atoi()` function converts the initial portion of the `string` pointed to by `nptr` to `int` and returns the converted value. |
| [`ft_bzero`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_bzero.c) | The `bzero()` function erases the data in the `n` bytes of the memory starting at the location pointed to by `s`, by writing zeros (bytes containing `'\0'`) to that area. |
| [`ft_calloc`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_calloc.c) | The `calloc()` function allocates memory for an array of `nmemb` elements of size bytes each and returns a pointer to the allocated memory. The memory is set to zero. |
| [`ft_isalnum`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_isalnum.c) | The `isalnum()` function checks whether the character is alphanumeric or not and returns a non-zero value if the character falls into the tested class, and zero if not. |
| [`ft_isalpha`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_isalpha.c) | The `isalpha()` function checks whether the character is alphabetic or not and returns a non-zero value if the character falls into the tested class, and zero if not. |
| [`ft_isascii`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_isascii.c) | The `isascii()` function checks whether the character is `ASCII` character or not and returns a non-zero value if the character falls into the tested class, and zero if not. |
| [`ft_isdigit`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_isdigit.c) | The `isdigit()` function checks whether the character is digit `0 - 9` or not and returns a non-zero value if the character falls into the tested class, and zero if not. |
| [`ft_isprint`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_isprint.c) | The `isprint()` function checks whether the character is printable (including space) or not and returns a non-zero value if the character falls into the tested class, and zero if not. |
| [`ft_memchr`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_memchr.c) | The `memchr()` function scans the initial `n` bytes of the memory area pointed to by `s` for the first instance of `c` and returns a pointer to the matching byte or `NULL` if the character does not occur in the given memory area. |
| [`ft_memcmp`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_memcmp.c) | The `memcmp()` function compares the first `n` bytes of the memory areas `s1` and `s2` and returns an integer less than, equal to, or greater than zero if the first `n` bytes of `s1` is found, respectively, to be less than, to match, or be greater than the first n bytes of `s2`. |
| [`ft_memcpy`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_memcpy.c) | The `memcpy()` function copies `n` bytes from the memory area `src` to memory area `dest` and returns a pointer to `dest`. The memory areas must not overlap. |
| [`ft_memmove`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_memmove.c) | The `memmove()` function copies `n` bytes from memory area `src` to memory area `dest` and returns a pointer to `dest`. The memory areas may overlap. |
| [`ft_memset`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_memset.c) | The `memset()` function fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `c` and returns a pointer to the memory area `s`. |
| [`ft_strchr`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_strchr.c) | The `strchr()` function returns a pointer to the first occurrence of the character `c` in the string `s`. |
| [`ft_strdup`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_strdup.c) | The `strdup()` function returns a pointer to a new string which is a duplicate of the string `s`. Memory for the new string is obtained with `malloc(3)`, and can be freed with `free(3)`. |
| [`ft_strlcat`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_strlcat.c) | The `strlcat()` function appends the NUL-terminated string `src` to the end of `dst` and returns the total length of the string they tried to create. |
| [`ft_strlcpy`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_strlcpy.c) | The `strlcpy()` function copies up to size - 1 characters from the NUL-terminated string `src` to `dst` and returns the total length of the string they tried to create. |
| [`ft_strlen`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_strlen.c) | The `strlen()` function calculates the length of the string pointed to by `s`, excluding the terminating null byte `'\0'` and returns the length. |
| [`ft_strncmp`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_strncmp.c) | The `strncmp()` function compares the two strings `s1` and `s2`, at most `n` bytes, and returns an integer less than, equal to, or greater than zero if `s1` is found, respectively, to be less than, to match, or be greater than `s2`. |
| [`ft_strnstr`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_strnstr.c) | The `strnstr()` function locates the first occurrence of the null-terminated string `little` in the string `big`, where not more than `n` characters are searched. If `little` is an empty string, `big` is returned; if `little` occurs nowhere in `big`, `NULL` is returned; otherwise, a pointer to the first character of the first occurrence of `little` is returned. |
| [`ft_strrchr`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_strrchr.c) | The `strrchr()` function returns a pointer to the last occurrence of the character `c` in the string `s`. |
| [`ft_tolower`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_tolower.c) | The `tolower()` function converts uppercase letters to lowercase and returns the converted letter. |
| [`ft_toupper`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_toupper.c) | The `toupper()` function converts lowercase letters to uppercase and returns the converted letter. |

### Aditional Functions

| Function | Description |
| :------: | :---------: |
| [`ft_itoa`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_itoa.c) |  |
| [`ft_putchar_fd`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_putchar_fd.c) |  |
| [`ft_putendl_fd`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_putendl_fd.c) |  |
| [`ft_putnbr_fd`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_putnbr_fd.c) |  |
| [`ft_putstr_fd`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_putstr_fd.c) |  |
| [`ft_striteri`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_striteri.c) |  |
| [`ft_strmapi`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_strmapi.c) |  |
| [`ft_strjoin`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_strjoin.c) |  |
| [`ft_substr`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_substr.c) |  |
| [`ft_strtrim`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_strtrim.c) |  |
| [`ft_split`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_split.c) |  |
<br>

## ⭐ Bonus

- Functions to manipulate memory and strings are very useful. But you will soon discover that manipulating `lists` is even more useful.
- You have to use the following structure to represent a `node` of your list:

```C
typedef	struct	s_list
{
	void		*content;
	struct	s_list	*next;
}			t_list;

```
### Bonus Functions

| Function | Description |
| :------: | :---------: |
| [`ft_lstadd_back`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_lstadd_back_bonus.c) |  |
| [`ft_lstclear`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_lstclear_bonus.c) | |
| [`ft_lstdelone`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_lstdelone_bonus.c) |  |
| [`ft_lstiter`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_lstiter_bonus.c) |  |
| [`ft_lstlast`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_lstlast_bonus.c) |  |
| [`ft_lstmap`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_lstmap_bonus.c) |  |
| [`ft_lstnew`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_lstnew_bonus.c) |  |
| [`ft_lstsize`](https://github.com/daniele-frade/42sp-cursus/blob/main/libft/ft_lstsize_bonus.c) |  |
