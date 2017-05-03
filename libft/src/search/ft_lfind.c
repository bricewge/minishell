/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_lfind(const void *key, t_arr array,
							int (*compar)(const void *, const void *))
{
	size_t		i;
	char		*arrmemb;

	i = -1;
	while (++i < *(array.nel))
	{
		arrmemb = (void*)array.base + (i * array.width);
		if (compar(key, arrmemb) == 0)
			return (arrmemb);
	}
	return (NULL);
}
