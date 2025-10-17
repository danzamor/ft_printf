# ft_printf
Reimplementation of the printf function in C, developed as part of the 42 curriculum, capable of handling formatted output with multiple conversions, flags, width, and precision.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Bonus Part](#bonus-part)
- [Author](#author)

---

## Overview
ft_printf is a reimplementation of the standard C printf function. It provides formatted output of text, numbers, and pointers, supporting multiple conversion specifiers, flags, width, and precision. This project was developed as part of the 42 curriculum to strengthen understanding of variadic functions, C standard library functions, and low-level string formatting.

## Features
ft_printf includes the following core functionalities:
- Supported conversions: %c, %s, %p, %d, %i, %u, %x, %X, and %%
- Supported flags: 0, -, +, #, and space ( )
- Field minimum width
- Precision control (. flag)
- Variadic function usage

## Project Structure
The repository is organized as follows:
- src: Source files for the mandatory part
- inc: Header files for the mandatory part
- bonus_src: Source files for the bonus part
- bonus_inc: Header files for the bonus part
- libft: Auxiliary functions in the library

## Usage
To compile and use ft_printf, run:
```bash
make
```
This generates the static library `libftprintf.a`, which you can link when compiling your programs.

Example usage:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "world");
    return 0;
}
```

## Bonus Part
To compile the ft_printf function with the bonus features, run:
```bash
make bonus
```
The bonus part extends ft_printf with additional features, including full support for all conversion specifiers, handling of all standard flags, and edge case management. This ensures more complete compatibility with the standard printf behavior.

Example of flags and conversion for a decimal argument:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("|%+-08.5d|\n", 42); // + flag, - flag, 0 padding, width 8, precision 5
    return 0;
}
```
```stdout
|+00042   |
```

## Author
- **Name:** Daniel Zamora
- **GitHub:** [danzamor](https://github.com/danzamor)
- **School:** 42
