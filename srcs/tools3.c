/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:31:04 by craffate          #+#    #+#             */
/*   Updated: 2017/02/07 14:33:45 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*getdate_ls(time_t t)
{
	char			*time;
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 4;
	time = ft_strnew(12);
	tmp = ctime(&t);
	while (tmp[j - 3] != ':')
		time[i++] = tmp[j++];
	return (time);
}
