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

static void		stripesc(char *str)
{
	int			i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] == 27)
			str = ft_strcpy(str + i, str + i + 3);
		else
			++i;
	}
}

static void		basic_varexpand(char *arg, int status)
{
	char		*env;

	if (ft_strequ(arg, "~"))
	{
		free(arg);
		arg = ft_strdup(ft_getenv("HOME"));
	}
	else if (arg[0] == '$')
	{
		if (arg[1] && (env = ft_getenv(&(arg[1]))))
		{
			free(arg);
			arg = ft_strdup(env);
		}
		else if (arg[1] == '?')
		{
			free(arg);
			arg = ft_strdup(ft_itoa(status));
		}
		else
			ft_strclr(arg);
	}
}

char			**sh_parse(char *line, int status)
{
	int			i;
	char		**args;

	args = ft_strsplit(line, ' ');
	i = -1;
	while (args[++i])
	{
		stripesc(args[i]);
		basic_varexpand(args[i], status);
	}
	return (args);
}
