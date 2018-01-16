/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 03:40:43 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/15 17:31:32 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

int		ft_isop(char op)
{
	int		i;
	
	i = -1;
	while (OP[++i])
	{
		if (ft_chrcmp(OP[i], op))
			return (1);
	}
	return (0);
}

int		get_exp(t_shunt *shnt)
{
	int		i;

	i = -1;
	while (shnt->data[++i])
	{
		if (!ft_chrcmp(shnt->data[i][0], '='))
			break ;
	}
	return (i);
}
