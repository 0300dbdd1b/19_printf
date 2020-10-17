#include "ft_printf.h"


int ft_check_format(const char *format, va_list *argptr)
{
	size_t	i;
	char 	*flags;
	int 	token;

	flags = FLAGS_CHARSET;
	i = 0;

	while(format[i])
	{
		if (i != 0 && format[i - 1] == '%')
		{
			token = (int)(ft_strchr(flags, format[i]) - flags);
			if (token != -1)
				(*fun_tab[token])(argptr);
		}
		else if (format[i] != '%')
			write(1, &format[i], 1);
		i++;
	}
	return (i);

}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		writed;

	va_start(argptr, format);
	writed = ft_check_format(format, &argptr);
	va_end(argptr);
	return (writed);
}

int main(void)
{
	int x = -9000888888888800880;
	char *str = " Coucou";

	printf("x = %x\n", x);
	ft_printf("x = %x\n", x);

	printf("str = %s\n", str);
	ft_printf("str = %s\n", str);


}