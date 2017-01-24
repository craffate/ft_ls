/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:05:20 by craffate          #+#    #+#             */
/*   Updated: 2017/01/17 15:40:42 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstrj2(wchar_t *s1, const wchar_t *s2)
{
	unsigned int	i;
	wchar_t			*s3;

	s3 = ft_wstrnew(ft_wstrlen(s1) + ft_wstrlen(s2));
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	free(s1);
	return (s3);
}

size_t	ft_extrabits_alt(const int c)
{
	size_t		i;

	i = 0;
	if (c >= 0x10000)
		i += 3;
	else if (c >= 0x800)
		i += 2;
	else if (c >= 0x80)
		i += 1;
	return (i);
}
