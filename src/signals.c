/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/10/11 17:47:53 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minishell.h"

static void			sigint(int signum)
{
	if (g_childpid != 0)
	{
		kill(g_childpid, signum);
		ft_putchar('\n');
		g_childpid = 0;
	}
	else
	{
		ft_putchar('\n');
		ft_putstr(PROMPT);
	}
}

void				signals(void)
{
	g_childpid = 0;
	signal(SIGINT, sigint);
}
