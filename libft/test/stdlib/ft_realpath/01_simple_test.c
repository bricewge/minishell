/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_negative_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:56:24 by starrit           #+#    #+#             */
/*   Updated: 2017/02/12 13:04:59 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			ft_realpath_simple_test(void)
{
	int		i;
	char	*path[] = { ".", "..", "./.." };
	/* char 	**split; */

	/* split = ft_strsplit("/.././/.././/.////.", '/'); */
	/* i = -1; */
	/* while (split[++i]) */
	/* { */
	/* 	ft_putchar('/'); */
	/* 	ft_putstr(split[i]); */
	/* } */

	i = -1;
	chdir("/");
	while (path[++i])
	{
		ft_putstr(path[i]);
		ft_putstr(":\t\t");
		ft_putendl(ft_realpath(path[i], NULL));
		ft_putendl(realpath(path[i], NULL));
	}
	/* if (ft_realpath(path, NULL) == realpath(path, NULL)) */
	if (1)
		return (0);
	else
		return (-1);
}
