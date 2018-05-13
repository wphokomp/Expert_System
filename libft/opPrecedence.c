#include "libft.h"

int     opPrecedence(char current_op, char new_op) {
    if (ft_strchr_indx(OP, current_op) > ft_strchr_indx(OP, new_op)) {
        return (1);
    }
    return (0);
}