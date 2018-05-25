#include "../inc/exp_sys.h"

bool	calculate(bool op1, bool op2, char operator)
{
	if (operator == '+')
	{
		return (op1 && op2);
	}
	else if (operator == '|')
	{
		return (op1 || op2);
	}
	else if (operator == '^')
	{
		return (op1 ^ op2);
	}
	else if (operator == '!')
	{
		return !(op1);
	}
	return false;
}
