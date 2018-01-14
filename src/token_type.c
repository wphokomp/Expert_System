/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 03:40:43 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/14 05:10:06 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

void	tokens(t_shunt *shnt)
{
	int		l;

	shnt->i = 0;
	shnt->j = 0;
	l = -1;
	while (*shnt->data && (!ft_chrcmp(*shnt->data, '=') || 
				!ft_chrcmp(*shnt->data)))
	{
		if (ft_isalpha(*data))
			shnt->i++;
		if (ft_chrcmp(*data))
			shnt->j++;
		*shnt->data++;
	}
}
