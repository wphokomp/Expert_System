/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 08:54:03 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/23 16:06:38 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

int		op_indx(char *op)
{
	int		i;

	i = -1;
	while (op[++i])
		if (!ft_isalpha(op[i]))
			return (i);
	return (0);
}

bool	compute(bool a, bool b, char op)
{
	if (op == '+')
		return (a & b);
	else if (op == '|')
		return (a | b);
	else if (op == '^')
		return (a ^ b);
	else 
		return (false);
}
/*
int		change_impl(t_shunt *shnt, bool res, int indx, int facts)
{
	int		j;
	int		chr_indx;
	int		ischange;

	ischange = 0;
	j = -1;
	chr_indx = 0;
	res = true;
	while (shnt->right[indx][++j])
	{
		chr_indx = ft_strchr_indx(shnt->no_dups, shnt->right[indx][j]);
		ft_putchar(shnt->no_dups[chr_indx]);
		if (ft_isalpha(shnt->right[indx][j]))
		{
			ft_putchar(shnt->right[indx][j]);
			if (shnt->ch_val[facts][chr_indx])
				ft_putendl("true");
			else
				ft_putendl("false");
		}
	}
	return (ischange);
}
*/
void	process(t_shunt *shnt)
{
	int		i;
	int		k;
	int		op_pos;
	int		f;
	int		tmp;
	bool	res;

	f = -1;
	shnt->facts = ft_getfacts(shnt);
	res = false;
	while (shnt->facts[++f])
	{
		tmp = -1;
		ft_putendl("\n====================");
		i = -1;
		k = 0;
		while (shnt->polish[++i])
		{
			shnt->st = 0;
			k = op_pos = op_indx(shnt->polish[i]);
			if (!op_pos)
			{
				res = shnt->ch_val[f][ft_strchr_indx(shnt->no_dups
						, shnt->polish[i][op_pos])];
			}
			while (op_pos < (int)ft_strlen(shnt->polish[i]) && op_pos > 0)
			{
				if (!shnt->st){
					shnt->A = shnt->ch_val[f][ft_strchr_indx(shnt->no_dups
							, shnt->polish[i][--k])];
				}
				else{
					shnt->A = res;
				}/*
					if (shnt->A)
					ft_putendl("ev A: true");
					else
					ft_putendl("ev A: false");
					*/	
				shnt->B = shnt->ch_val[f][ft_strchr_indx(shnt->no_dups
						, shnt->polish[i][--k])];
				/*
				   if (shnt->B)
				   ft_putendl("ev B: true");
				   else
				   ft_putendl("ev B: false");
				   */
				if (shnt->polish[i][op_pos] == '!')
				{
					shnt->A = !shnt->A;
					op_pos++;
				}
				res = compute(shnt->A, shnt->B, shnt->polish[i][op_pos]);
				//Call function change_impl(t_shunt *shnt, bool)	
				op_pos++;
				shnt->st++;
			}
			//tmp = change_impl(shnt, res, i, f);
			if (res)
				ft_putendl("res is true");
			else
				ft_putendl("res is false");
		}
		//ft_putnbrendl(tmp);
		//if (f == ft_strlen_point(shnt->facts) && tmp == 1)
		//	f = -1;
	}
}
