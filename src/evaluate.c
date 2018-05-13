#include "../inc/exp_sys.h"

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
    // calculateExpression(values, stack, shunting) {

    // }
}