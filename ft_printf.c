#include "ft_printf.h"

int	ft_formats(va_list args, char c)
{
	int	buffer;

	buffer = 0;
	if (c == 'c')
		buffer += ft_printchar(va_arg(args, int));
	else if (c == '%')
		buffer += ft_putpercent();
	else if (c == 's')
		buffer += ft_printstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		buffer += ft_printnbr(va_arg(args, int));
	return (buffer);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				buffer;
	unsigned int	i;

	i = 0;
	buffer = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			buffer += ft_formats(args, str[i]);
		}
		else
		{
			ft_printchar(str[i]);
			buffer++;
		}
		i++;
	}
	va_end(args);
	return (buffer);
}

// int	main(void)
// {
// 	int teste = -2147483648;
// int teste2 = -21;
// 	ft_printf("%i\n", teste);
//   	ft_printf("%i", teste2);
// }
