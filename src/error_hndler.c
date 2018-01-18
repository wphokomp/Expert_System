/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hndler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:52:40 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/18 10:52:43 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

void    get_err(int err_num)
{
    if (err_num == 1)
        ft_putendl("\x1b[31mOops! The file you tried to access is not valid or does not exist!\x1b[0m");
    else if (err_num == 2)
        ft_putendl("\x1b[31mOops! The format used is incorrect!\x1b[0m");
	else if (err_num == 3)
		 ft_putendl("\x1b[31mUsage: ./expert_system [FILE]\x1b[0m");

    else
        ft_putendl("\x1b[31mOops! There seems to be an error!\x1b[0m");
}
