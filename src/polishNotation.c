#include "../inc/exp_sys.h"

void    checkBrackets(t_shunting *shunting, int outQ, char token) {
    int     stackLen;

    stackLen = 0;
    if (token == '(') { //CHECK IF THERE ARE ANY BRACKETS
        shunting->stack[stackLen] = '(';
    } else if (token == ')') {
        stackLen = ft_strlen(shunting->stack);
        while (--stackLen >= 0){
            //WHILE THERE'S NO OPENING BRACKET, POP FROM STACK TO QUEUE
            if (shunting->stack[stackLen] != '(') {
                shunting->queue[++outQ] = shunting->stack[stackLen];
                shunting->stack[stackLen] = '\0';
            } else {
                shunting->stack[stackLen] = '\0';
            }
        }
        //????CAN'T SEE THE PLUS! WHERE IS MY PLUS???
    }
}

void    popFromStackToQueue(t_shunting *shunting) {
    int     stackLen;
    int     outQ;

    stackLen = ft_strlen(shunting->stack);
    outQ = ft_strlen(shunting->queue);
    while (--stackLen >= 0) {
        shunting->queue[outQ] = shunting->stack[stackLen];
        shunting->stack[stackLen] = '\0';
        outQ++;
    }
    ft_putendl(shunting->queue);
    ft_putstr(shunting->stack);
    free(shunting->stack);
}

void    polishNotation(t_shunting *shunting) {
    int     i;
    int     outQ;
    int     stackLen;

    i = -1;
    outQ = -1;
    shunting->stack = ft_strnew(ft_strlen(shunting->expressions[0]));
    shunting->queue = ft_strnew(ft_strlen(shunting->expressions[0]));
    //(B+C)|!F
    while (shunting->expressions[0][++i] != '\0') {
        if (ft_isalpha(shunting->expressions[0][i])) { //IF IT'S A VALUE, ADD IT TO THE QUEUE
            shunting->queue[++outQ] = shunting->expressions[0][i];
        } else if (op(shunting->expressions[0][i])) { 
            stackLen = ft_strlen(shunting->stack);
            while (--stackLen >= 0) { //IF OPERATOR, CHECK IF ANY OF THE ONES ON THE STACK HAVE HIGHER PRECEDENCE
                if (opPrecedence(shunting->expressions[0][i]) < 
                opPrecedence(shunting->stack[stackLen]) 
                && shunting->stack[stackLen] != '(' && shunting->stack[stackLen] != ')') {
                    shunting->queue[++outQ] = shunting->stack[stackLen];
                    shunting->stack[stackLen] = '\0';
                } else {
                    break;
                }
            }
            //PUSH THE CURRENT OPERATOR INTO THE STACK
            shunting->stack[ft_strlen(shunting->stack)] = shunting->expressions[0][i];
        } else {
            if (shunting->expressions[0][i] == '(') { //CHECK IF THERE ARE ANY BRACKETS
                shunting->stack[stackLen] = '(';
            } else if (shunting->expressions[0][i] == ')') {
                stackLen = ft_strlen(shunting->stack);
                while (--stackLen >= 0){
                    //WHILE THERE'S NO OPENING BRACKET, POP FROM STACK TO QUEUE
                    if (shunting->stack[stackLen] != '(') {
                        shunting->queue[++outQ] = shunting->stack[stackLen];
                        shunting->stack[stackLen] = '\0';
                    } else {
                        shunting->stack[stackLen] = '\0';
                    }
                }
                //????CAN'T SEE THE PLUS! WHERE IS MY PLUS???
            }
            // checkBrackets(shunting, outQ, shunting->expressions[0][i]);
        }
    }
    // ft_putendl(shunting->queue);
    popFromStackToQueue(shunting);
}