/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorHandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:51:36 by lmucassi          #+#    #+#             */
/*   Updated: 2018/05/25 17:52:50 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

void	getError(int error)
{
	if (error == 1)
		ft_putendl("File does not exist.");
	else if (error == 2)
		ft_putendl("Format of the file is invalid.");
	else if (error == 3)
		ft_putendl("Usage: ./expert_system [FILE_NAME]");
	else if (error == 4)
		ft_putendl("Test file not wwritten according to standard");
	else
		ft_putendl("There seems to be an error.");
	exit(0);
}
