#include "../inc/exp_sys.h"

int		is_changed()
{
	if()
	{
		return (1);
	}
	return (0);
}

bool calculate(bool op1, bool op2, char _operator) {
    if (_operator == '+') {
        return (op1 && op2);
    } else if (_operator == '|') {
        return (op1 || op2);
    } else if (_operator == '^') {
        return (op1 ^ op2);
    } else if (_operator == '!') {
        return !(op1);
    }
    return false;
}
