#include "ft_printf.h"


void ft_printf_char(va_list *argptr)
{
	char c;

	c = va_arg(*argptr, int); 
	write(1, &c, 1);
}

void ft_printf_str(va_list *argptr)
{
	char *str;

	str = va_arg(*argptr, char *);
	write(1, str, ft_strlen(str));
}

void ft_printf_ptr(va_list *argptr)
{
	int num;
}

void ft_printf_decimal(va_list *argptr)
{
	int num;

	num = va_arg(*argptr, int);
	ft_putnbr(num);
}

void ft_printf_integer(va_list *argptr)
{
	int num;

	num = va_arg(*argptr, int);
	ft_putnbr(num);
}