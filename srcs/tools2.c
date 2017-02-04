/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 01:11:19 by craffate          #+#    #+#             */
/*   Updated: 2017/02/04 01:15:36 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	*arrnew(size_t s)
{
	size_t			*arr;
	unsigned int	i;

	if (!(arr = malloc(sizeof(size_t) * s)))
		return (0);
	while (i != s)
		arr[i++] = 0;
	return (arr);
}
