/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 23:52:17 by craffate          #+#    #+#             */
/*   Updated: 2016/12/03 16:52:31 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(int n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n /= 10)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	size_t	i;
	char	*s;
	int		neg;

	neg = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	i = ft_getsize(n) + 1;
	if (!(s = (char *)(malloc(sizeof(char) * i + 1))))
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	s[i] = '\0';
	while (i--)
	{
		s[i] = n % 10 + 48;
		n /= 10;
	}
	if (neg)
		s[0] = 45;
	return (s);
}
