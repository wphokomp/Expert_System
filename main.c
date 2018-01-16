#include "inc/exp_sys.h"

int		main(void)
{
	char	*exp = "G | C + A => D";
	t_shunt	*shnt;
	int		i;
	int		j;

	shnt->op = shnt->ch = shnt->op_len = i = 0;
	j = 0;
	shnt->polish = ft_listnew(1);
	
	shnt->stack = ft_strnew(ft_strlen(exp));
	shnt->queue = ft_strnew(ft_strlen(exp));
	while (exp[i] && ft_chrcmp(exp[i], '=') != 0)
	{
		if (ft_isalpha(exp[i]))
			shnt->queue[j++] = exp[i];
		if (ft_isop(exp[i]))
		{
			shnt->op_len = ft_strlen(shnt->stack)i - 1;
			while (shnt->op_len >= 0)
				if (ft_strchr_indx(OP, exp[i]) < 
						ft_strhr_indx(OP, shnt->stack[shnt->op_len]))
				{
					shnt->queue[j] = shnt->stack[shnt->op_len--];
				}
			shnt->stack[shnt->op_len] = exp[i];
		}
		shnt->op = ft_strlen(shnt->stack);
		if (ft_chrcmp(exp[i], '(') == 0)
			shnt->stack[shnt->op++] = exp[i];
		else if (ft_chrcmp(exp[i], ')') == 0)
		{
			while (ft_chrcmp(shnt->stack[shnt->op], '(') != 0)
			{
				shnt->queue[j++] = shnt->stack[shnt->op];
				shnt->stack[shnt->op] = '\0';
				shnt->op--;
			}
		}
		shnt->op = ft_strlen(shnt->stack);
		while (shnt->op >= 0)
			shnt->queue[j++] = shnt->stack[shnt->op--];
		shnt->polish[shnt->ch] = ft_strdup(shnt->queue);
	}
	while (exp)
}
