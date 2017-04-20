/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_getenv(const char *name)
{
	char		**envp;
	char		*value;
	int			len;
	int			i;

	if (!name)
		return (NULL);
	envp = ft_environ(NULL);
	len = ft_strlen(name);
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(name, envp[i], len) == 0)
		{
			value = ft_strchr(envp[i], '=');
			if (value[0] == '=')
				value += 1;
			return (value);
		}
	}
	return (NULL);
}
