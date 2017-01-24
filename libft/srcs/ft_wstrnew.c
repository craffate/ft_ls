/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:35:25 by craffate          #+#    #+#             */
/*   Updated: 2017/01/10 11:36:45 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t			*s;
	unsigned int	i;

	if (!(s = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1))))
		return (NULL);
	i = 0;
	s[size] = '\0';
	while (i < size)
		s[i++] = '\0';
	return (s);
}
