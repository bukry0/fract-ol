/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:03:53 by bcili             #+#    #+#             */
/*   Updated: 2025/03/31 15:03:53 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (NULL == s1 || NULL == s2)
		return (0);
	while (*s1 == *s2 && *s1 != '\0')
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s++)
		++len;
	return (len);
}

void	putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

double	atodbl(char *s)
{
	long		int_part;
	double		frac_part;
	double		power;
	int			sign;

	int_part = 0;
	frac_part = 0;
	sign = 1;
	power = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*s++ - 48);
	if ('.' == *s)
		s++;
	while (*s)
	{
		power /= 10;
		frac_part = frac_part + (*s++ - 48) * power;
	}
	return ((int_part + frac_part) * sign);
}
