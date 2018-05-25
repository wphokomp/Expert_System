/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:53:53 by lmucassi          #+#    #+#             */
/*   Updated: 2018/05/25 17:59:02 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exp_sys.h"

/*
 * void calculateExpression(struct Struct *values, struct Struct *stack)
 * {
   bool operand1;
   bool operand2;

   while (!isEmpty(values)) {
   if (lastItem(stack) != '!') {
   operand1 = popBool(values);
   operand2 = popBool(values);
   push(value, calculate(operand1, operand2, pop(stack)));
   } else if (lastItem(stack) == '!') {
   operand1 = popBool(values);
   push(value, calculate(operand1, operand2, pop(stack)));
   }
   }
   ft_putnbr(popBool(values));
   }
   */
void	separate(struct Stack *queue, t_shunting *shunting, char *data)
{
	struct	Stack *values;
	struct	Stack *stack;
	char	something;

	values = createBoolStack(ft_strlen(data));
	stack = createStack(ft_strlen(data));
	while (ft_isalpha(something = pop(queue)) || op(something))
	{
		if (ft_isalpha(something))
		{
			pushBool(values,
					shunting->booleanVal[shunting->factIndx]
					[ft_strchr_indx(shunting->operands,
						something)]);
		}
		else if (op(something))
		{
			push(stack, something);
		}
	}
	/*
	 * calculateExpression(values, stack);
	 * */
}
