/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:26:52 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/28 01:11:34 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"
/*
void	change(bool res, int *j, t_shunt *shnt, char *ch)
{
	int		i;

	i = -1;
	if (res){
		while 
	}
}*/

int		ft_countright(t_shunt *shnt)
{
	int		cnt;
	int		i;

	shnt->st = -1;
	cnt = 0;
	i = -1;
	while (shnt->data[++i])
	{
		if (shnt->data[i][0] == '=')
			break ;
		while (shnt->data[i][++shnt->st])
			if (ft_isalpha(shnt->data[i][shnt->st]))
				cnt++;
	}
	return (cnt);
}

void	is_dup(t_shunt *shnt)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = -1;
	shnt->no_dups = ft_strnew(ft_countright(shnt) + 1);
	tmp = ft_strnew(ft_countright(shnt));
	while (shnt->data[++i])
	{
		shnt->st = -1;
		if (shnt->data[i][0] == '=')
			break ;
		while (shnt->data[i][++shnt->st])
			if (ft_isalpha(shnt->data[i][shnt->st]))
				tmp[++j] = shnt->data[i][shnt->st];
	}
	ft_sortarr(tmp);
	i = -1;
	j = -1;
	while (++i < (int)ft_strlen(tmp) - 1)
		if (tmp[i] != tmp[i + 1])
			shnt->no_dups[++j] = tmp[i];
	shnt->no_dups[++j] = tmp[i];
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
			facts[++fact_cnt] = ft_strtrim(shnt->data[i] + 1);
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
