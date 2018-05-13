#include "../inc/exp_sys.h"

void    convertToPostfix(char *data) {
    int i;
    char token;
    // struct Stack *values;
    struct Stack *queue;
    struct Stack *stack;

    i = -1;
    queue = createStack(ft_strlen(data));
    stack = createStack(ft_strlen(data));
    while (data[++i]) {
        if (ft_isalpha(data[i])) {
            push(queue, data[i]);
        } else if (op(data[i])) {
            if (op(lastItem(stack))) {
                if (opPrecedence(lastItem(stack), data[i])) {
                    push(queue, pop(stack));
                }
            }
            push(stack, data[i]);
        } else if (data[i] == '(') {
            push(stack, data[i]);
        } else if (data[i] == ')') {
            while (lastItem(stack) != '(') {
                push(queue, pop(stack));
            }
            pop(stack);
        }
    }
    while (op(token = pop(stack))) { push(queue, token); }
    // values = getValues(queue);
    // while (ft_isalpha(token = pop(queue)) || op(token)) {
    //     ft_putchar(token);
    // }
    // ft_putchar('\n');
}

void    getExpressions(char **data) {
    int     i;

    i = -1;
    while (data[++i]) {
        if (data[i][0] != '=') {
            if (data[i][0] != '?'){
                convertToPostfix(ft_strsub(data[i], 0, ft_strchr_indx(data[i], '=')));
            }
        }
    }
}