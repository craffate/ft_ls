/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:36:34 by craffate          #+#    #+#             */
/*   Updated: 2017/01/10 07:37:48 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(int n, int b)
{
	size_t size;

	size = 1;
	while (n /= b)
		size += 1;
	return (size);
}

char			*ft_itoa_base(int n, int b)
{
	char				*s;
	size_t				len;

	len = ft_getsize(n, b);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	s[len--] = 0;
	while (n >= b)
	{
		s[len--] = ("0123456789abcdef")[n % b];
		n /= b;
	}
	s[len--] = ("0123456789abcdef")[n % b];
	return (s);
}
