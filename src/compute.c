/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 08:54:03 by wphokomp          #+#    #+#             */
/*   Updated: 2018/03/09 19:52:05 by wphokomp         ###   ########.fr       */
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

bool	compute(bool a, bool b, char op, int *call)
{
	*call = 1;
	if (op == '+')
		return (a & b);
	else if (op == '|')
		return (a | b);
	else if (op == '^')
		return (a ^ b);
	else 
		return (false);
}

int		op_type(char *rhs)
{
	int		i;

	i = -1;
	while (rhs[++i]){
		if (rhs[i] == '+')
			return (1);
		else if (rhs[i] == '|')
			return (2);
		else if (rhs[i] == '!')
			return (3);
	}
	return (0);
}

int		change_impl(t_shunt *shnt, int fact, int indx, bool res)
{
	int		j;
	int		ischange;

	ischange = 0;
	j = -1;
	if (ft_strlen(shnt->right[indx]) == 1)
	{
		if (res != shnt->ch_val[fact][ft_strchr_indx(shnt->no_dups
					, shnt->right[indx][0])]){
			shnt->ch_val[fact][ft_strchr_indx(shnt->no_dups
					, shnt->right[indx][0])] = res;
			ischange = 1;
		}
	}
	else if (ft_strlen(shnt->right[indx]) == 2)
		shnt->ch_val[fact][ft_strchr_indx(shnt->no_dups
					, shnt->right[indx][0])] = !res;
	else{
		if (op_type(shnt->right[indx]) == 1){
			while (shnt->right[indx][++j]){
				shnt->ch_val[fact][ft_strchr_indx(shnt->no_dups
						, shnt->right[indx][j])] = res;
				//ft_putchar(shnt->right[indx][j]);
			}
		}
		else if (op_type(shnt->right[indx]) == 2){
			while (ft_isalpha(shnt->right[indx][++j])){
				if (ft_isalpha(shnt->right[indx][j])){
					shnt->ch_val[fact][ft_strchr_indx(shnt->no_dups
							, shnt->right[indx][j])] = !res;
				}
			}
		}
	}
	return (ischange);
}

void	process(t_shunt *shnt)
{
	int		ischange;
	int		re = 0;

	shnt->que = 1;
	// while (shnt->facts[++shnt->que])
	// {
		shnt->st = 1;
		re = 0;
		ischange = 0;
		//ft_putstr(shnt->facts[shnt->que]);
		//ft_putendl("============");
		autonom(shnt);
	// }
}
