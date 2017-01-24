/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:37:37 by craffate          #+#    #+#             */
/*   Updated: 2017/01/23 15:23:49 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrjoin(const wchar_t *s1, const wchar_t *s2)
{
	size_t	i;
	wchar_t	*s3;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	if (!(s3 = (wchar_t *)malloc(sizeof(wchar_t) *
		(ft_wstrlen(s1) + ft_wstrlen(s2) + 1))))
		return (NULL);
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (*&s3);
}
