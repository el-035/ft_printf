# ft_printf

`ft_printf` is my implementation of the mandatory part of C's `printf`, created
as part of the 42 curriculum. It parses a format string, writes formatted output
to standard output, and returns the number of characters printed.

## Supported conversions

| Specifier | Output |
| --- | --- |
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer address |
| `%d`, `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x`, `%X` | Lowercase or uppercase hexadecimal |
| `%%` | Percent sign |

## Build

```sh
git clone <repository-url>
cd ft_printf
make
```

This creates the static library `libftprintf.a`.

## Usage

Include the header:

```c
#include "ft_printf.h"
```

Then compile and link your program with the library:

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
    return (0);
}
```

The project practises variadic functions, format parsing, number conversion,
and low-level output with `write`.
