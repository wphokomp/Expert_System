/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:26:52 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/18 15:38:15 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

void	is_dup(t_shunt *shnt)
{
	int i;
	int j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	printf("I am her");
	while (shnt->polish[i])
	{
		printf("i am here 1");
		while(ft_isalpha(shnt->polish[i][j]))
		{
			printf("i am here 2");
		/*	if (ft_strchr(shnt->no_dups, shnt->polish[i][j]))
				j++;
			else
			{
				shnt->no_dups[k++] = shnt->polish[i][j];
				j++;
			}
			ft_putendl(&shnt->no_dups[k]);*/
		}
		j = 0;
		i++;
	}
}
