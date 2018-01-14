/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:11:21 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/14 08:11:16 by wphokomp         ###   ########.fr       */
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
/*
char	**getPolish(void)
{
	t_shunt	*shnt;
	char	**data;

	data = express(NULL);
	while (!ft_chrcmp(*shnt->data[0], '='))
	{
		shnt->j = 0;
		while (data[sh.i][sh.j] != '=' || data[sh.i][sh.j] != '<')
		{
			if (ft_isalpha(data[sh.i][sh.j]))

		}
	}
}*/
