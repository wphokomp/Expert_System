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

void updateValues(bool value, t_shunting *shunting) {
    if (ft_strchr_indx(shunting->operands, shunting->rightOperands[shunting->indx]) > -1) {
        if (shunting->booleanVal[shunting->factIndx]
            [ft_strchr_indx(shunting->operands, shunting->rightOperands[shunting->indx])] != value) {
                shunting->booleanVal[shunting->factIndx]
            [ft_strchr_indx(shunting->operands, shunting->rightOperands[shunting->indx])] = value;
            };
        
    }
    pushBool(shunting->answers, value);
}

void calculateExpression(struct Stack *values, struct Stack *stack, t_shunting *shunting) {
    bool    op1;
    bool    op2;
    struct Stack *tmp;
    char    _operator;

    tmp = createBoolStack(values->capacity);
    while (!isEmpty(values)) {
        if (lastItem(stack) != '!') {
            if (values->capacity > 1) {
                op1 = popBool(values);
                op2 = popBool(values);
                _operator = pop(stack);
                pushBool(tmp, calculate(op1, op2, _operator));
            } else {
                pushBool(tmp, popBool(values));
            }
            break ;
        } else if (lastItem(stack) == '!') {
            pushBool(tmp, !popBool(values));
        }
    }
    updateValues(popBool(tmp), shunting);
    free(tmp);
}

void    separate(struct Stack *queue, t_shunting *shunting, char *data) {
    struct Stack *values;
    struct Stack *stack;
    char    something;

    values = createBoolStack(ft_strlen(data));
    stack = createStack(ft_strlen(data));
    while (ft_isalpha(something = pop(queue)) || op(something)) {
        if (ft_isalpha(something)) {
            pushBool(values, shunting->booleanVal[shunting->factIndx][ft_strchr_indx(shunting->operands, something)]);
        } else if (op(something)) {
            push(stack, something);
        }
    }
    calculateExpression(values, stack, shunting);
}