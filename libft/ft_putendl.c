/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbopp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:10:52 by lbopp             #+#    #+#             */
/*   Updated: 2017/01/05 14:30:46 by lbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
