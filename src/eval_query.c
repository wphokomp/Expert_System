/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:11:21 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/15 17:23:33 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

char	*get_queries(char **data)
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
}

void	getPolish(t_shunt *shnt)
{
	int		i;
	int		j;
	int		x;

	x = -1;
	shnt->ch = -1;
	shnt->polish = ft_listnew(get_exp(shnt));
	while (!ft_chrcmp(shnt->data[++x][0], '=') && shnt->data[x])
	{
		i = -1;
		j = -1;
		shnt->op = 0;
		shnt->stack = ft_strnew(ft_strlen(shnt->data[x]));
		shnt->queue = ft_strnew(ft_strlen(shnt->data[x]));
		while (shnt->data[x][++i] != '=' || shnt->data[x][i] != '<')
		{
			if (ft_isalpha(shnt->data[x][i]))
				shnt->queue[++j] = shnt->data[x][i];
			if (ft_isop(shnt->data[x][i]))
			{
				shnt->op_len = ft_strlen(shnt->stack);
				while (shnt->op_len)
					if (shnt->op_len > 0 && 
							ft_strchr_indx(OP, shnt->data[x][i]) < 
							ft_strchr_indx(OP, shnt->stack[shnt->op_len]))
					{
						shnt->queue[++j] = shnt->stack[shnt->op_len--];
						//shnt->stack[shnt->op_len] = '\0';
					}
				shnt->stack[shnt->op_len] = shnt->data[x][i];
			}
			shnt->op = ft_strlen(shnt->stack);
			if (!ft_chrcmp(shnt->data[x][i], '('))
				shnt->stack[shnt->op++] = shnt->data[x][i];
			else if (!ft_chrcmp(shnt->data[x][i], ')'))
			{
				while (ft_chrcmp(shnt->stack[shnt->op], '('))
					shnt->queue[++j] = shnt->stack[shnt->op--];
				shnt->stack[shnt->op] = '\0';
			}
		}
		while (shnt->op >= 0)
			shnt->queue[j++] = shnt->stack[shnt->op--];
		shnt->polish[++shnt->ch] = ft_strdup(shnt->queue);
	}
	if (x == ft_strlen_point(shnt->data))
	{
		ft_putendl("\x1b[31mFormat incorrect\x1b[0m");
		exit(0);
	}
}
