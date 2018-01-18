/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:11:21 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/18 11:11:43 by lmucassi         ###   ########.fr       */
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

void	add_op(char c, t_shunt *shnt)
{
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

void	add_alph_brack(char c, t_shunt *shnt)
{
	/*if (ft_isalpha(c))
	  {
	  shnt->queue[shnt->que] = c;
	  shnt->que++;
	  }*/
	add_op(c, shnt);
	if (!ft_chrcmp(c, '('))
		shnt->stack[shnt->st_len] = c;
	else if (!ft_chrcmp(c, ')'))
	{
		while (ft_chrcmp(shnt->stack[--shnt->st_len], ')') != 0)
		{
			shnt->queue[shnt->que] = shnt->stack[shnt->st_len];
			shnt->que++;
			shnt->stack[shnt->st_len] = '\0';
		}
		shnt->stack[shnt->st_len] = '\0';
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

void	get_polish(t_shunt *shnt)
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
				//add_op(shnt->data[i][cnt], shnt);
				shnt->st_len = ft_strlen(shnt->stack);
				/*	
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
					}*/
				add_alph_brack(shnt->data[i][cnt], shnt);
			}
			cnt++;
		}
		while (--shnt->st_len >= 0)
		{
			shnt->queue[shnt->que] = shnt->stack[shnt->st_len];
			shnt->que++;
		}
		//ft_putendl(shnt->queue);
		i++;
	}
	if (i == ft_strlen_point(shnt->data))
	{
		get_err(FOMT_ERR);
		exit(0);
	}
}
