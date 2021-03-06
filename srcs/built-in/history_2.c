/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbopp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 21:12:49 by lbopp             #+#    #+#             */
/*   Updated: 2017/11/04 22:13:18 by lbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		nflag(t_control **history, char *file)
{
	int		a;
	int		fd;
	char	*str;

	a = 0;
	fd = open(file, O_RDWR, S_IRUSR | S_IWUSR | S_IROTH);
	if (fd == -1)
		return ;
	while (get_next_line(fd, &str) && a < (*history)->original_length)
	{
		ft_strdel(&str);
		a++;
	}
	if (str && *str)
		(*history) = dll_add_new_elem_frnt(*history, str);
	ft_strdel(&str);
	while (get_next_line(fd, &str))
	{
		(*history) = dll_add_new_elem_frnt(*history, str);
		ft_strdel(&str);
	}
	if (str && *str)
		(*history) = dll_add_new_elem_frnt(*history, str);
	ft_strdel(&str);
	close(fd);
}

int			rewrite_hist_file(t_control **history, char *file_name)
{
	int		fd;
	t_lst	*tmp;

	if ((*history) == NULL)
		return (0);
	fd = open(file_name,
		O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IROTH);
	if (fd == -1)
		return (-1);
	tmp = (*history)->end;
	while (tmp != NULL)
	{
		ft_putendl_fd(tmp->name, fd);
		tmp = tmp->prev;
	}
	close(fd);
	return (0);
}

int			append_hist_file(t_control **history, char *file_name)
{
	int		fd;
	char	*str;

	fd = open(file_name, O_RDWR);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &str))
	{
		*history = dll_add_new_elem_frnt(*history, str);
		ft_strdel(&str);
	}
	ft_strdel(&str);
	close(fd);
	return (0);
}

void		print_pflag(char **tab)
{
	int		a;

	a = 2;
	while (tab[a])
	{
		ft_putendl(tab[a]);
		a++;
	}
}

int			str_isdigit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
