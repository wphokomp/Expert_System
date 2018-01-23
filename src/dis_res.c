/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:00:51 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/23 16:09:36 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

void	final(t_shunt *shnt)
{
	ft_putendl("\x1b[33m=========================================\x1b[0m");
	ft_putendl("\x1b[33m\tCalculating Results From Expressions\x1b[0m");
	/*
 	* 	call process() to dispaly all the results here */
 	 process(shnt);
 	
	ft_putendl("\x1b[33m\t\t\tDone!!!\x1b[0m");
	ft_putendl("\x1b[33m=========================================\x1b[0m");
}
