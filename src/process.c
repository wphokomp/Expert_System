/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:26:52 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/20 01:53:00 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

void	is_dup(t_shunt *shnt)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = -1;
	shnt->no_dups = ft_strnew(shnt->ch);
	tmp = ft_strnew(shnt->ch);
	while (shnt->polish[++i])
	{
		shnt->st = -1;
		while (shnt->polish[i][++shnt->st])
			if (ft_isalpha(shnt->polish[i][shnt->st]))
				tmp[++j] = shnt->polish[i][shnt->st];
	}
	ft_sortarr(tmp);
	i = -1;
	j = -1;
	while (++i < (int)ft_strlen(tmp) - 1)
		if (tmp[i] != tmp[i + 1])
			shnt->no_dups[++j] = tmp[i];
	shnt->no_dups[++j] = tmp[i++];
}

char	**ft_getfacts(t_shunt *shnt)
{
	int		i;
	int		fact_cnt;
	char	**facts;

	i = -1;
	fact_cnt = 0;
	while (shnt->data[++i])
		if (shnt->data[i][0] == '=')
			fact_cnt++;
	if (!fact_cnt)
		get_err(2);
	if (!(facts = ft_strnew_point(fact_cnt)))
		return (NULL);
	i = -1;
	fact_cnt = -1;
	while (shnt->data[++i])
		if (shnt->data[i][0] == '=')
			facts[++fact_cnt] = ft_strdup(shnt->data[i] + 1);
	ft_getquery(shnt);
	return (facts);
}

void	ft_getquery(t_shunt *shnt)
{
	int		i;

	i = -1;
	while (shnt->data[++i])
	{
		if (shnt->data[i][0] == '?')
			shnt->query = ft_strdup(shnt->data[i] + 1);
	}
}
