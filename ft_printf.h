#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

# ifndef FLAGS_NUMBER
#  define FLAGS_NUMBER 10
# endif
# ifndef FLAGS_CHARSET
#  define FLAGS_CHARSET "cspdiuxX%"
# endif


void ft_printf_char(va_list *argptr);
void ft_printf_str(va_list *argptr);
void ft_printf_ptr(va_list *argptr);
void ft_printf_decimal(va_list *argptr);
void ft_printf_integer(va_list *argptr);
void ft_printf_unsigned(va_list *argptr);
void ft_printf_hex(va_list *argptr);


int	    ft_printf(const char *format, ...);


static void (*fun_tab[FLAGS_NUMBER]) (va_list *) = {ft_printf_char, ft_printf_str, ft_printf_ptr, ft_printf_decimal, ft_printf_integer, ft_printf_unsigned, ft_printf_hex, 0, 0, 0};

#endif