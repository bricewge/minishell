/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_putenv(char *string)
{
	int			ret;
	char		*name;
	char		*value;

	if (!string)
		return (-1);
	value = ft_strchr(string, '=') + 1;
	name = ft_strsub(string, 0, value - string - 1);
	ret = ft_setenv(name, value, 1);
	free(name);
	return (ret);
}
