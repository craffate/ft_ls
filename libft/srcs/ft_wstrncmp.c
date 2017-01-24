/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:41:40 by craffate          #+#    #+#             */
/*   Updated: 2017/01/12 15:43:41 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrncmp(const wchar_t *s1, const wchar_t *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 && *s1 == *s2 && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (*(wchar_t *)--s1 - *(wchar_t *)--s2);
	return (*(wchar_t *)s1 - *(wchar_t *)s2);
}
