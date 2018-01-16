#include "inc/exp_sys.h"

int		main(void)
{
	char	*exp;
	int		i;
	int		st;
	int		st_len;
	int		j;
	t_shunt	shnt;

	exp = ft_strdup("G | C + (A | D)  => D");
	st = i = shnt.op = j = 0;
	shnt.stack = ft_strnew(ft_strlen(exp));
	shnt.queue = ft_strnew(ft_strlen(exp));
	while (exp[i] && ft_chrcmp(exp[i], '=') != 0)
	{
		if (ft_isalpha(exp[i]))
		{
			shnt.queue[shnt.op] = exp[i];
			shnt.op++;
		}
		if (ft_isop(exp[i]))
		{
			st = ft_strlen(shnt.stack);
			while (ft_strchr_indx(OP, exp[i]) < 
					ft_strchr_indx(OP, shnt.stack[st])){
				shnt.queue[shnt.op] = shnt.stack[st];
				st--;
			}
			st_len = ft_strlen(shnt.stack);
			shnt.stack[st_len] = exp[i];
		}
		st_len = ft_strlen(shnt.stack);
		if (!ft_chrcmp(exp[i], '('))
		{
			shnt.stack[st_len] = exp[i];
			st_len++;
		}
		else if (!ft_chrcmp(exp[i], ')'))
		{
			while (ft_chrcmp(shnt.stack[--st_len], '(') != 0){
				shnt.queue[shnt.op] = shnt.stack[st_len];
				shnt.op++;
				shnt.stack[st_len] = '\0';
			}
			shnt.stack[st_len] = '\0';
		}
		i++;
	}
	ft_putendl(shnt.stack);
	while (--st_len >= 0)
	{
		shnt.queue[shnt.op] = shnt.stack[st_len];
		shnt.op++;
	}
	ft_putendl(shnt.queue);
	free(shnt.stack);
	return (0);
}
