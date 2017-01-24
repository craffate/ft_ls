/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:19:49 by craffate          #+#    #+#             */
/*   Updated: 2016/12/03 17:01:59 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_blankcheck(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			j;
	unsigned int	k;
	char			*s2;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (ft_blankcheck(s[j - 1]))
		j--;
	while (ft_blankcheck(s[i]))
		i++;
	if (!s[i])
	{
		s2 = ft_strnew(0);
		return (s2);
	}
	k = j - i;
	s2 = ft_strsub(s, i, k);
	return (s2);
}
