/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:41:08 by craffate          #+#    #+#             */
/*   Updated: 2016/12/03 17:02:55 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordscounter(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[j++])
		if (s[j] == c && s[j + 1] != c)
			i++;
	if (s[0] != '\0')
		i++;
	return (i);
}

static char		*ft_elements(char const *s, char c, unsigned int *i)
{
	char			*w;
	unsigned int	j;

	j = 0;
	if (!(w = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[*i] != c && s[*i])
	{
		w[j] = s[*i];
		j++;
		*i += 1;
	}
	w[j] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (w);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**arr;
	unsigned int	words;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	words = ft_wordscounter(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (j < words && s[i])
	{
		arr[j] = ft_elements(s, c, &i);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
