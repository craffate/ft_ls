/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:22:07 by craffate          #+#    #+#             */
/*   Updated: 2017/01/10 15:30:27 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(const wchar_t *s1)
{
	unsigned int	i;
	wchar_t			*arr;

	i = 0;
	if (!(arr = (wchar_t *)malloc(sizeof(wchar_t) * ft_wstrlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
