/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbopp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:43:41 by lbopp             #+#    #+#             */
/*   Updated: 2017/11/05 15:59:37 by lbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		subspe(char *new, char *str, int *i, int *j)
{
	char	c;

	c = str[(*i)];
	new[(*j)++] = str[(*i)++];
	while (str[*i] && str[*i] != c)
		new[(*j)++] = str[(*i)++];
	new[(*j)++] = str[*i];
}
