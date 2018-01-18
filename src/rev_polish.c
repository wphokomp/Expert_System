/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 03:40:43 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/18 11:09:39 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

/*
void	do_brackOp(t_shunt shnt, int *i, int *cnt)
{
	if (!ft_chrcmp(shnt->data[i][cnt]. '('))
	{
		shnt->stack[shnt->st_len] = shnt->data[i][cnt];
		shnt->st_len++;
	}
	else if (!ft_chrcmp(shnt->data[i][cmp], ')'))
	{
		while (ft_chrcmp(shnt->stack[--shnt->st_len], '(') != 0)
		{
			shnt->queue[shnt->que] = shnt->stack->st_len];
			shnt->que++;
			shntstack[shnt->st_len] = '\0';
		}
		shnt->stack[shnt->st_len] = '\0';
	}

*/

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
