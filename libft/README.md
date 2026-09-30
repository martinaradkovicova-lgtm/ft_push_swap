*This project has been created as part of the 42 curriculum by hpiotrow.*

# Libft

## DESCRIPTION
The Libft project focuses on creating a custom static library. 
It reimplements some standard functions from Libc library, 
as well as includes some custom functions.

The result of this project is an archive file `libft.a`, which compiles individual `.c`
files into `.o` binary files, which are then packed together using the `ar` archiver.

It is written in C, and includes the following functions, listed by categories:

#### For linked lists manipulation: 
ft_lstnew.c - Allocates memory and creates a new node.
ft_lstadd_front.c - Adds a new node at the beginning of the list.
ft_lstsize.c - Counts the number of nodes in the list.
ft_lstlast.c - Returns the last node of the list.
ft_lstadd_back.c - Adds a new node at the end of the list.
ft_lstdelone.c - Deletes content and frees one node.
ft_lstclear.c - Deletes content and frees the node and its successors (deletes list). 
ft_lstiter.c - Iterates through the list and applies function 'f' to each node.
ft_lstmap.c - Iterates through the list and applies function 'f' to each node, creates a new list with results.

#### For character manipulation:
ft_isalpha.c - Checks if character is alphabetic.
ft_isdigit.c - Checks if character is a digit.
ft_isalnum.c - Checks if character is alphanumeric.
ft_isascii.c - Checks if character is ASCII.
ft_isprint.c - Checks if character is printable.
ft_toupper.c - Converts character to uppercase.
ft_tolower.c - Converts character to lowercase.

#### For string manipulation:
ft_strlen.c - Counts length of the string.
ft_strlcpy.c - Copies the source string to destination, up to dest limit. Returns src size.
ft_strchr.c - Locates the first occurrence of a character in a string.
ft_strrchr.c - Locates the last occurrence of a character in a string.
ft_strncmp.c - Compares two strings, up to the given size.
ft_strlcat.c - Attaches a string to another string, up to the given size of buffer. Returns total size of both strings.
ft_strnstr.c - Locates a string within another string.
ft_atoi.c - Converts a string of numerical characters into an integer. Skips initial spaces, tracks +/-.
ft_strdup.c - Allocates memory, duplicates a string, returns a pointer to a new string.
ft_substr.c - Creates a new substring by allocating memory and copying a certain number of characters.
ft_strjoin.c - Allocates memory and joins two strings into one new string.
ft_strtrim.c - Allocates memory and creates new string by trimming characters from both ends of the string.
ft_split.c - Creates an array of new strings by splitting a string at certain character.
ft_itoa.c - Converts an integer into a string of numerical characters.
ft_strmapi.c - Creates new string by applying a custom function to every character of a string.
ft_striteri.c - Loops through the string and applies a custom function to each character in-place.

#### For memory manipulation:
ft_memset.c - Fills a specified number of bytes with a given value.
ft_bzero.c - Fills a specified number of bytes with zeros (erases them).
ft_memcpy.c - Copies a specified number of bytes from src to dest, without checking for overlap.
ft_memmove.c - Safely copies bytes from src to dest, by first checking if they overlap.
ft_memchr.c - Locates a value in a memory block.
ft_memcmp.c - Compares two memory blocks.
ft_calloc.c - Allocates a clean memory block by erasing it.

#### For writing to file descriptors:
ft_putchar_fd.c - Writes a single character to a specified FD output.
ft_putstr_fd.c - Writes a string to a specified FD output.
ft_putendl_fd.c - Writes a string to a specified FD output, followed by a new line.
ft_putnbr_fd.c - Converts int to char and writes digits to a specified FD output.

## INSTRUCTIONS
The library includes a `Makefile` that compiles it with flags `-Wall -Wextra -Werror`.

Available commands:

```bash
make
```
To compile the library and generate the `libft.a` file at the root directory.

```bash
make clean
```
To remove all generated object binary files (`.o`).

```bash
make fclean
```
To remove all object files and the compiled `libft.a` library.

```bash
make re
```
To remove everything and compile the files again.

## RESOURCES

### References
[GeeksforGeeks](https://www.geeksforgeeks.org/) Various resources on writing functions, 
headers, makefiles, linked lists.
[Linux Manual Pages (Man2)](https://man7.org/linux/man-pages/man2/) Manual pages for
standard library functions.
[Makefile Tutorial by Example](https://makefiletutorial.com/) Makefile tutorial.

### AI Usage
Artificial Intelligence was used in a limited capacity for this project, mainly to find
resources and help debugging. Specifically, AI was leveraged for the following tasks:
1.  **Fixing Syntax and formatting:** Assisting in debugging syntax errors within the `Makefile`
 and `libft.h`, as well as formatting the `README`.
2.  **Error Log Analysis:** Translating compiler warnings into plain English to
optimize debugging during local testing.
3.  **Finding Resources:** Finding resources online for the specific tasks, as listed above.