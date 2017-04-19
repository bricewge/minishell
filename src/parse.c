/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**sh_parse(char *line, int status)
{
	int			i;
	char		**args;
	char		*env;

	args = ft_strsplit(line, ' ');
	i = -1;
	while (args[++i])
	{
		if (ft_strequ(args[i], "~"))
		{
			free(args[i]);
			args[i] = ft_strdup(ft_getenv("HOME"));
		}
		else if (args[i][0] == '$')
		{
			if (args[i][1] && (env = ft_getenv(&(args[i][1]))))
			{
				free(args[i]);
				args[i] = ft_strdup(env);
			}
			else if ('?')
			{
				free(args[i]);
				args[i] = ft_strdup(ft_itoa(status));
			}
			else
				ft_strclr(args[i]);
		}
	}
	return (args);
}
