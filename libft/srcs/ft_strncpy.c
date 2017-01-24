/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:36:48 by craffate          #+#    #+#             */
/*   Updated: 2016/11/05 18:08:19 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*s;

	s = dst;
	while (len > 0 && *src)
	{
		*s++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*s++ = '\0';
		len--;
	}
	return (dst);
}
