/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxbasic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:42:37 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/04/29 15:52:42 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_printchar(int c)
{
	int	i;

	i = 0;
	write(1, &c, 1);
	i += 1;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_printchar(s[i]);
		i++;
	}
}

int	ft_putpercent(void)
{
	return (ft_printchar('%'));
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
	{
		ft_printchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int			len;
	char		*nbr;
	long long	ln;

	len = 0;
	ln = n;
	if (ln < 0 && ln != -2147483648)
	{
		len += ft_printchar('-');
		ln *= -1;
	}
	if (ln == -2147483648)
	{
		ft_printstr("-2147483648");
		return (11);
	}
	nbr = ft_itoa(ln);
	len += ft_printstr(nbr);
	free(nbr);
	return (len);
}
