/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:22:46 by craffate          #+#    #+#             */
/*   Updated: 2017/01/12 10:25:20 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrchr(const wchar_t *s, int c)
{
	while (*s && *s != (wchar_t)c)
		s++;
	return (*s == (wchar_t)c ? (wchar_t *)s : NULL);
}
