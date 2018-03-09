/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:11:21 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/26 00:07:41 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

int		ft_isop(char op);

void	add_op(char c, t_shunt *shnt)
{
	if (ft_isalpha(c))
	{
		shnt->queue[shnt->que] = c;
		shnt->que++;
		shnt->ch++;
	}
	if (op(c))
	{
		shnt->st = ft_strlen(shnt->stack);
		while (ft_strchr_indx(OP, c) < ft_strchr_indx(OP, c))
		{
			shnt->queue[shnt->que] = shnt->stack[shnt->st];
			shnt->st--;
		}
		shnt->stack[ft_strlen(shnt->stack)] = c;
	}
}

void	get_right(t_shunt *shnt)
{
	int	i;
	int	pos;

	i = -1;
	shnt->right = ft_strnew_point(get_exp(shnt, shnt->data));
	while (++i < get_exp(shnt, shnt->data))
	{
		pos = ft_strchr_indx(shnt->data[i], '>') + 1;
		shnt->right[i] = ft_strtrim(shnt->data[i] + pos);
	}
}

void	rev_polish(char c, t_shunt *shnt)
{
	add_op(c, shnt);
	shnt->st_len = ft_strlen(shnt->stack);
	do_brack(shnt, c);
}

int		exp_len(char *str)
{
	int		i;
	int		l;

	i = 0;
	l = -1;
	while (str[++l])
		if (ft_isop(str[l]) || ft_isalpha(str[l]))
			i++;
	return (i);
}

void	get_polish(t_shunt *shnt, char **data)
{
	int		i;
	int		cnt;

	i = 0;
	shnt->polish = ft_listnew(get_exp(shnt, data));
	while (ft_chrcmp(data[i][0], '=') != 0 && data[i][0] != '?')
	{
		cnt = 0;
		init(shnt, i);
		shnt->polish[i] = ft_strnew(exp_len(data[i]));
		while (data[i][cnt])
		{
			if (!ft_chrcmp(data[i][cnt], '<') ||
					!ft_chrcmp(data[i][cnt], '='))
				break ;
			else
				rev_polish(data[i][cnt], shnt);
			cnt++;
		}
		push_into(shnt, i);
		i++;
	}
	if (i == ft_strlen_point(data))
		get_err(FOMT_ERR);
	get_right(shnt);
	is_dup(shnt);
}
