/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 02:27:53 by craffate          #+#    #+#             */
/*   Updated: 2016/11/15 02:31:54 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorial(int n)
{
	int	res;

	res = 1;
	if (n == 0)
		return (res);
	if (n < 0 || n > 12)
		return (0);
	if (n > 0)
		res = n * ft_factorial(n - 1);
	return (res);
}
