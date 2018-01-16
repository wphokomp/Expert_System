/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:11:21 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/16 17:16:06 by wphokomp         ###   ########.fr       */
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
	int		cnt;

	i = 0;
	shnt->polish = ft_listnew(get_exp(shnt));
	while (ft_chrcmp(shnt->data[i][0], '=') != 0)
	{
		cnt = 0;
		shnt->que = 0;
		shnt->st = 0;
		shnt->st_len = 0;
		shnt->queue = ft_strnew(ft_strlen(shnt->data[i]));
		shnt->stack = ft_strnew(ft_strlen(shnt->data[i]));
		while (shnt->data[i][cnt])
		{
			if (!ft_chrcmp(shnt->data[i][cnt], '<') || 
					!ft_chrcmp(shnt->data[i][cnt], '='))
				break ;
			else
			{
				if (ft_isalpha(shnt->data[i][cnt]))
				{
					shnt->queue[shnt->que] = shnt->data[i][cnt];
					shnt->que++;
				}
				if (ft_isop(shnt->data[i][cnt]))
				{
					shnt->st = ft_strlen(shnt->stack);
					while (ft_strchr_indx(OP, shnt->data[i][cnt]) < 
							ft_strchr_indx(OP, shnt->stack[shnt->st]))
					{
						shnt->queue[shnt->que] = shnt->stack[shnt->st];
						shnt->st--;
					}
					shnt->st_len = ft_strlen(shnt->stack);
					shnt->stack[shnt->st_len] = shnt->data[i][cnt];
				}
				shnt->st_len = ft_strlen(shnt->stack);
				if (!ft_chrcmp(shnt->data[i][cnt], '('))
				{
					shnt->stack[shnt->st_len] = shnt->data[i][cnt];
					shnt->st_len++;
				}
				else if (!ft_chrcmp(shnt->data[i][cnt], ')'))
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
			cnt++;
		}
		//ft_putendl(shnt->queue);
		while (--shnt->st_len >= 0)
		{
			shnt->queue[shnt->que] = shnt->stack[shnt->st_len];
			shnt->que++;
		}
		ft_putendl(shnt->queue);
		//shnt->polish[i] = ft_strtrim(shnt->queue);
		//free(shnt->queue);
		i++;
	}
	//ft_putendl(shnt->polish[0]);
	if (i == ft_strlen_point(shnt->data))
	{
		ft_putendl("\x1b[31mFormat incorrect\x1b[0m");
		exit(0);
	}
}
