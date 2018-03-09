/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 03:40:43 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/26 00:05:49 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

void	do_brack(t_shunt *shnt, char c)
{
	if (!ft_chrcmp(c, '('))
	{
		shnt->stack[shnt->st_len] = c;
		shnt->st_len++;
	}
	else if (!ft_chrcmp(c, ')'))
	{
		while (ft_chrcmp(shnt->stack[--shnt->st_len], '(') != 0)
		{
			shnt->queue[shnt->que] = shnt->stack[shnt->st_len];
			shnt->que++;
			shnt->stack[shnt->st_len] = '\0';
		}
		shnt->stack[shnt->st_len] = '\0';
	}
}

void	push_into(t_shunt *shnt, int i)
{
	while (--shnt->st_len >= 0)
	{
		shnt->queue[shnt->que] = shnt->stack[shnt->st_len];
		shnt->que++;
	}
	shnt->polish[i] = ft_strtrim(shnt->queue);
}

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

int		get_exp(t_shunt *shnt, char **data)
{
	int		i;

	i = -1;
	while (data[++i])
	{
		if (!ft_chrcmp(shnt->data[i][0], '='))
			break ;
	}
	return (i);
}
