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

static void		cleanup_line(char *str)
{
	int			iread;
	int			iwrite;

	if (!str)
		return ;
	iread = 0;
	iwrite = 0;
	while (iwrite <= iread)
	{
		if (iwrite < iread)
			str[iwrite] = str[iread];
		if (str[iread] == 27)
			iread += 2;
		else if (str[iread] == '\t')
			;
		else
			++iwrite;
		if (str[iread])
			++iread;
	}
}

static void		basic_varexpand(char **arg, int status)
{
	char		*env;

	if (ft_strequ(*arg, "~"))
	{
		free(*arg);
		*arg = ft_strdup(ft_getenv("HOME"));
	}
	else if (*(arg[0]) == '$')
	{
		if ((*arg)[1] && (env = ft_getenv(&(*arg)[1])))
		{
			free(*arg);
			*arg = ft_strdup(env);
		}
		else if ((*arg)[1] == '?')
		{
			free(*arg);
			*arg = ft_itoa(status);
		}
		else
			ft_strclr(*arg);
	}
}

char			**sh_parse(char *line, int status)
{
	int			i;
	char		**args;

	cleanup_line(line);
	args = ft_strsplit(line, ' ');
	i = -1;
	while (args[++i])
	{
		basic_varexpand(&(args[i]), status);
	}
	return (args);
}
