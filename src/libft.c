/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_freearr(char **pstr)
{
	int			i;

	i = -1;
	while (pstr[++i])
		free(pstr[i]);
	free(pstr);
}

int				ft_puterror(char *msg, char *name, int errnum)
{
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(name, 2);
	return (errnum);
}
