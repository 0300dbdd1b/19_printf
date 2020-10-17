#include "ft_printf.h"

void ft_printf_unsigned(va_list *argptr)
{
	int num;

	num = va_arg(*argptr, unsigned int);
	ft_putnbr(num);
}

void ft_printf_hex(va_list *argptr)
{
	int num;

	num = va_arg(*argptr, unsigned int);
	ft_putnbr_base(num, "0123456789abcdef");
}