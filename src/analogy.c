/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analogy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 02:34:08 by wphokomp          #+#    #+#             */
/*   Updated: 2018/03/09 19:05:22 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

bool	get_boolval(t_shunt *shnt, int ch)
{
	if (ft_strlen(shnt->polish[shnt->st]) == 1)
		return (shnt->ch_val[shnt->que][ft_strchr_indx(shnt->no_dups
						, shnt->polish[shnt->st][0])]);
	else {
		return (shnt->ch_val[shnt->que][ft_strchr_indx(shnt->no_dups
				, shnt->polish[shnt->st][ch])]);
	}
}

void	autonom(t_shunt *shnt)
{
	char	*exp = shnt->polish[1];
	char	op, operator = 0;
	bool	res;
	int		call = 0;
	int		op_pos, char_pos;

	char_pos = op_pos = op_indx(exp);
	while (--char_pos >= 0) {
		op = exp[op_pos++];
		shnt->A = get_boolval(shnt, char_pos--);
		if (op == '!') {
			shnt->A = !shnt->A;
			operator = exp[op_pos++];
		}
		else
			operator = op;
		op = exp[op_pos] ? exp[op_pos++] : '0';
		shnt->B = get_boolval(shnt, char_pos--);
		if (op == '!') {
			shnt->B = !shnt->B;
		}
		else if (op != '0'){
			operator = op;
		}
		res = compute(shnt->A, shnt->B, operator, &call);
		ft_putendl(exp);
		ft_putchar(exp[char_pos]);
		ft_putchar(exp[op_pos]);
		ft_putnbrendl(ft_strlen(exp));
		break ;
	}
	// while (shnt->polish[++shnt->st]){
	// 	char_pos = op_pos = op_indx(shnt->polish[shnt->st]);
	// 	if (!op_pos)
	// 		res = get_boolval(shnt, char_pos);
	// 	else {
	// 		while (--char_pos >= 0) {
	// 			op = shnt->polish[shnt->st][op_pos++];
	// 			shnt->A = get_boolval(shnt, char_pos--);
	// 			if (op == '!') {
	// 				shnt->A = !shnt->A;
	// 				operator = shnt->polish[shnt->st][op_pos++];
	// 			}
	// 			else
	// 				operator = op;
	// 			op = shnt->polish[shnt->st][op_pos] ? shnt->polish[shnt->st][op_pos++] : '0';
	// 			shnt->B = get_boolval(shnt, char_pos--);
	// 			if (op == '!') {
	// 				shnt->B = !shnt->B;
	// 			}
	// 			else if (op != '0'){
	// 				operator = op;
	// 			}
	// 			res = compute(shnt->A, shnt->B, operator, &call);
	// 		}
	// 	}
	// }
}
