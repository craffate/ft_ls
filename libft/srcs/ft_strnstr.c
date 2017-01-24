/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:54:30 by craffate          #+#    #+#             */
/*   Updated: 2016/12/03 16:59:28 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	size_t			l;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char *)big);
	l = ft_strlen(little);
	while (big[i] && len >= l)
	{
		j = 0;
		k = i;
		while (big[k] == little[j])
		{
			j++;
			k++;
			if (little[j] == '\0')
				return (&((char *)big)[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}
