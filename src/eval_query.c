/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:11:21 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/22 13:06:58 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

/*char	*get_queries(char **data)
{
	int		i;
	size_t	len;
	size_t	data_len;
	char	*queries;

	i = -1;
	len = ft_strlen(data[ft_strlen_point(data) - 1]);
	data_len = ft_strlen_point(data) - 1;
	queries = ft_strnew(len);
	while (data[data_len][++i])
		queries[i] = data[data_len][i];
	return (queries + 1);
}*/

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
	shnt->right = ft_strnew_point(get_exp(shnt));
	while (++i < get_exp(shnt))
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

void	get_polish(t_shunt *shnt)
{
	int		i;
	int		cnt;

	i = 0;
	shnt->polish = ft_listnew(get_exp(shnt));
	while (ft_chrcmp(shnt->data[i][0], '=') != 0 && shnt->data[i][0] != '?')
	{
		cnt = 0;
		init(shnt, i);
		while (shnt->data[i][cnt])
		{
			if (!ft_chrcmp(shnt->data[i][cnt], '<') ||
					!ft_chrcmp(shnt->data[i][cnt], '='))
				break ;
			else
				rev_polish(shnt->data[i][cnt], shnt);
			cnt++;
		}
		push_into(shnt, i);
		i++;
	}
	if (i == ft_strlen_point(shnt->data))
		get_err(FOMT_ERR);
	get_right(shnt);
	is_dup(shnt);
	store_val(shnt);
}
