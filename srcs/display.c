/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:14:58 by craffate          #+#    #+#             */
/*   Updated: 2017/02/02 22:25:03 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*rights(t_file *file)
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

static long long int total(t_file **dir)
{
	long long int	t;

	t = 0;
	while (*dir)
	{
		t += (**dir).stat.st_blocks;
		dir++;
	}
	return (t);
}

static void	display_l(t_file *dir, int i, size_t s)
{
	S_ISSOCK((*dir).stat.st_mode) ?
	ft_printf("%s %2u %s  %s %*u {white}%s{eoc}\n", rights(dir), (*dir).stat.st_nlink, getpwuid((*dir).stat.st_uid)->pw_name, getgrgid((*dir).stat.st_gid)->gr_name, s, (*dir).stat.st_size, (*dir).name) : 0;
	S_ISLNK((*dir).stat.st_mode) ?
	ft_printf("%s %2u %s  %s %*u {yellow}%s{eoc}\n", rights(dir), (*dir).stat.st_nlink, getpwuid((*dir).stat.st_uid)->pw_name, getgrgid((*dir).stat.st_gid)->gr_name, s, (*dir).stat.st_size, (*dir).name) : 0;
	S_ISDIR((*dir).stat.st_mode) ?
	ft_printf("%s %2u %s  %s %*u {cyan}%s{eoc}\n", rights(dir), (*dir).stat.st_nlink, getpwuid((*dir).stat.st_uid)->pw_name, getgrgid((*dir).stat.st_gid)->gr_name, s, (*dir).stat.st_size, (*dir).name) : 0;
	S_ISREG((*dir).stat.st_mode) ?
	ft_printf("%s %2u %s  %s %*u %s\n", rights(dir), (*dir).stat.st_nlink, getpwuid((*dir).stat.st_uid)->pw_name, getgrgid((*dir).stat.st_gid)->gr_name, s, (*dir).stat.st_size, (*dir).name) : 0;
}

void		display(t_file **dir, int i, const unsigned short status, size_t s)
{
	unsigned int	j;

	j = 0;
	(i & LS_L) && status == 1 ? ft_printf("Total: %lld\n", total(dir)) : 0;
	while (dir[j])
	{
		if (!(i & LS_L))
		{
			S_ISSOCK((*dir[j]).stat.st_mode) ?
			ft_printf("{white}%s{eoc}\t", (*dir[j]).name) : 0;
			S_ISLNK((*dir[j]).stat.st_mode) ?
			ft_printf("{yellow}%s{eoc}\t", (*dir[j]).name) : 0;
			S_ISDIR((*dir[j]).stat.st_mode) ?
			ft_printf("{cyan}%s{eoc}\t", (*dir[j]).name) : 0;
			S_ISREG((*dir[j]).stat.st_mode) ?
			ft_printf("%s\t", (*dir[j]).name) : 0;
		}
		else if (i & LS_L)
			display_l(dir[j], i, s);
		j++;
	}
}
