/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:37:49 by craffate          #+#    #+#             */
/*   Updated: 2016/11/25 16:14:23 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_save(char **s, char **tmp, char ***line)
{
	*tmp = ft_strdup(*s);
	if (**tmp == '\n')
	{
		free(*s);
		*s = ft_strdup(*tmp + 1);
		**line = ft_strnew(0);
		return (1);
	}
	free(*s);
	*s = ft_strchr(*tmp, '\n') ?
	ft_strdup(ft_strchr(*tmp, '\n') + 1) : ft_strnew(0);
	if (ft_strchr(*tmp, '\n'))
		*ft_strchr(*tmp, '\n') = '\0';
	**line = *tmp;
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static char		*s;
	char			*tmp;

	if (fd < 0)
		return (-1);
	if (!s)
		s = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = ft_strjoin(s, buf);
		free(s);
		s = ft_strdup(tmp);
		free(tmp);
		if (ft_strchr(s, '\n'))
			break ;
	}
	if (ft_save(&s, &tmp, &line))
		return (1);
	return (!!(*tmp));
}
