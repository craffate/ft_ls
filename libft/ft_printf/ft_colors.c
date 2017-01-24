/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:47:52 by craffate          #+#    #+#             */
/*   Updated: 2017/01/17 15:49:11 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*ft_invcolor(const char *format, wchar_t **s)
{
	size_t			i;
	unsigned int	j;
	wchar_t			*tmp;

	i = 0;
	j = 0;
	*s = ft_wstrj2(*s, L"{");
	while (*format != '%' && *format != '}' && *format != '{')
		i++;
	tmp = ft_wstrnew(i);
	while (i > 0)
	{
		tmp[j++] = *format++;
		i--;
	}
	if (*tmp)
		*s = ft_wstrj2(*s, tmp);
	free(tmp);
	return (format);
}

static int			ft_wstrncmp_alt(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 && *s1 == *s2 && i < n)
	{
		s1++;
		s2++;
		i++;
		if (i == n)
			return (1);
	}
	return (0);
}

const char			*ft_colors(const char *format, wchar_t **s)
{
	if (ft_wstrncmp_alt(format, "{eoc}", 5) && (*s = ft_wstrj2(*s, EOC)))
		return (format + 5);
	else if (ft_wstrncmp_alt(format, "{red}", 5) && (*s = ft_wstrj2(*s, RED)))
		return (format + 5);
	else if (ft_wstrncmp_alt(format, "{green}", 7) &&
			(*s = ft_wstrj2(*s, GREEN)))
		return (format + 7);
	else if (ft_wstrncmp_alt(format, "{yellow}", 8) &&
			(*s = ft_wstrj2(*s, YELLOW)))
		return (format + 8);
	else if (ft_wstrncmp_alt(format, "{blue}", 6) &&
			(*s = ft_wstrj2(*s, BLUE)))
		return (format + 6);
	else if (ft_wstrncmp_alt(format, "{magenta}", 9) &&
			(*s = ft_wstrj2(*s, MAGENTA)))
		return (format + 9);
	else if (ft_wstrncmp_alt(format, "{cyan}", 6) &&
			(*s = ft_wstrj2(*s, CYAN)))
		return (format + 6);
	else if (ft_wstrncmp_alt(format, "{white}", 7) &&
			(*s = ft_wstrj2(*s, WHITE)))
		return (format + 7);
	else
		format = ft_invcolor(format + 1, s);
	return (format);
}
