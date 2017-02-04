/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:14:58 by craffate          #+#    #+#             */
/*   Updated: 2017/02/05 02:52:47 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char				*rights(t_file *file)
{
	unsigned int	i;
	char			*s;

	i = 0;
	s = ft_strnew(10);
	s[i++] = *(S_ISDIR((*file).stat.st_mode) ? "d" : "-");
	s[i++] = *((*file).stat.st_mode & S_IRUSR ? "r" : "-");
	s[i++] = *((*file).stat.st_mode & S_IWUSR ? "w" : "-");
	s[i++] = *((*file).stat.st_mode & S_IXUSR ? "x" : "-");
	s[i++] = *((*file).stat.st_mode & S_IRGRP ? "r" : "-");
	s[i++] = *((*file).stat.st_mode & S_IWGRP ? "w" : "-");
	s[i++] = *((*file).stat.st_mode & S_IXGRP ? "x" : "-");
	s[i++] = *((*file).stat.st_mode & S_IROTH ? "r" : "-");
	s[i++] = *((*file).stat.st_mode & S_IWOTH ? "w" : "-");
	s[i] = *((*file).stat.st_mode & S_IXOTH ? "x" : "-");
	return (s);
}

/*
**static void				display_l_alt(t_file *dir, int i, size_t *schars)
**{
**
**}
*/

void				display_l(t_file *dir, int i, size_t *schars)
{
	S_ISSOCK((*dir).stat.st_mode) ?
	ft_printf("%-11s %*u %-*s  %-*s %*u {white}%s{eoc}\n", rights(dir), schars[3],
	(*dir).stat.st_nlink, schars[0], getpwuid((*dir).stat.st_uid)->pw_name,
	schars[1], getgrgid((*dir).stat.st_gid)->gr_name, schars[2],
	(*dir).stat.st_size, (*dir).name) : 0;
	S_ISLNK((*dir).stat.st_mode) ?
	ft_printf("%-11s %*u %-*s  %-*s %*u {yellow}%s{eoc}\n", rights(dir), schars[3],
	(*dir).stat.st_nlink, schars[0], getpwuid((*dir).stat.st_uid)->pw_name,
	schars[1], getgrgid((*dir).stat.st_gid)->gr_name, schars[2],
	(*dir).stat.st_size, (*dir).name) : 0;
	S_ISDIR((*dir).stat.st_mode) ?
	ft_printf("%-11s %*u %-*s  %-*s %*u {cyan}%s{eoc}\n", rights(dir), schars[3],
	(*dir).stat.st_nlink, schars[0], getpwuid((*dir).stat.st_uid)->pw_name,
	schars[1], getgrgid((*dir).stat.st_gid)->gr_name, schars[2],
	(*dir).stat.st_size, (*dir).name) : 0;
	S_ISREG((*dir).stat.st_mode) ?
	ft_printf("%-11s %*u %-*s  %-*s %*u %s\n", rights(dir), schars[3],
	(*dir).stat.st_nlink, schars[0], getpwuid((*dir).stat.st_uid)->pw_name,
	schars[1], getgrgid((*dir).stat.st_gid)->gr_name, schars[2],
	(*dir).stat.st_size, (*dir).name) : 0;
//	display_l_alt(dir, i, schars);
}

void					display_nl(t_file *dir, int i, size_t *schars)
{
	S_ISSOCK((*dir).stat.st_mode) ?
	ft_printf("{white}%s{eoc}\n", (*dir).name) : 0;
	S_ISLNK((*dir).stat.st_mode) ?
	ft_printf("{yellow}%s{eoc}\n", (*dir).name) : 0;
	S_ISDIR((*dir).stat.st_mode) ?
	ft_printf("{cyan}%s{eoc}\n", (*dir).name) : 0;
	S_ISREG((*dir).stat.st_mode) ? ft_printf("%s\n", (*dir).name) : 0;

}

void					display(t_file **dir, int i, size_t *schars)
{
	unsigned int	j;

	j = 0;
	while (dir[j])
	{
		if (!(i & LS_L))
			display_nl(dir[j], i, schars);
		else if (i & LS_L)
			display_l(dir[j], i, schars);
		j++;
	}
}
