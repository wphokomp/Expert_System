/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbrac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:29:49 by wphokomp          #+#    #+#             */
/*   Updated: 2018/01/16 16:31:12 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isbrac(char ch)
{
	if (!ft_chrcmp(ch, ')') || !ft_chrcmp(ch, '('))
		return (1);
	return (0);
}