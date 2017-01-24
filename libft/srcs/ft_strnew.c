/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:19:42 by craffate          #+#    #+#             */
/*   Updated: 2016/12/03 16:58:36 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*s;
	unsigned int	i;

	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	s[size] = '\0';
	while (i < size)
		s[i++] = '\0';
	return (s);
}
