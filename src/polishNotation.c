#include "../inc/exp_sys.h"

void	removeDuplicates(char *ch, t_shunting *shunting, int caller)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (caller == 0) {
        shunting->operands = ft_strnew(NO_OF_CHARS);
        ft_sortarr(ch);    
        while (++i < (int)ft_strlen(ch) - 1)
            if (ch[i] != ch[i + 1])
                shunting->operands[++j] = ch[i];
        shunting->operands[++j] = ch[i++];
    } else if (caller == 1) {
        shunting->rightOperands = ft_strnew(NO_OF_CHARS);
        ft_sortarr(ch);    
        while (++i < (int)ft_strlen(ch) - 1)
            if (ch[i] != ch[i + 1])
                shunting->rightOperands[++j] = ch[i];
        shunting->rightOperands[++j] = ch[i++];
    }
}

void	getValues(char **data, t_shunting *shunting)
{
	int		i;
	int		c;
	int		ch_indx;
	char	*tmp;
	char	*ch;

	i = -1;
	ch_indx = -1;
	ch = ft_strnew(25);
	while (data[++i])
	{
		c = -1;
		if (data[i][0] != '=')
		{
			if (data[i][0] != '?')
			{
				tmp = ft_strsub(data[i], 0, ft_strchr_indx(data[i], '='));
				while (tmp[++c])
				{
					if (ft_isalpha(tmp[c]))
					{
						ch[++ch_indx] = tmp[c];
					}
				}
				shunting->_sindx++;
			}
		}
	}
	removeDuplicates(ch, shunting, 0);
}

void getRightValues(t_shunting *shunting) {
    int		i;
	int		c;
	int		ch_indx;
	char	*tmp;
	char	*ch;

	i = -1;
	ch_indx = -1;
	ch = ft_strnew(25);
	while (shunting->evalExpression[++i])
	{
		c = -1;
		if (shunting->evalExpression[i][0] != '=')
		{
			if (shunting->evalExpression[i][0] != '?')
			{
				tmp = ft_strsub(shunting->evalExpression[i], 0, ft_strchr_indx(shunting->evalExpression[i], '='));
				while (tmp[++c])
				{
					if (ft_isalpha(tmp[c]))
					{
						ch[++ch_indx] = tmp[c];
					}
				}
			}
		}
	}
	removeDuplicates(ch, shunting, 1);
}

void	convertToPostfix(char *data, t_shunting *shunting)
{
	int		i;
	char	token;
	struct	Stack *queue;
	struct	Stack *stack;

	i = -1;
	queue = createStack(ft_strlen(data));
	stack = createStack(ft_strlen(data));
	while (data[++i])
	{
		if (ft_isalpha(data[i]))
		{
			push(queue, data[i]);
		}
		else if (op(data[i]))
		{
			if (op(lastItem(stack)))
			{
				if (opPrecedence(lastItem(stack), data[i]))
				{
					push(queue, pop(stack));
				}
			}
			push(stack, data[i]);
		}
		else if (data[i] == '(')
		{
			push(stack, data[i]);
		}
		else if (data[i] == ')')
		{
			while (lastItem(stack) != '(')
			{
				push(queue, pop(stack));
			}
			pop(stack);
		}
	}
	while (op(token = pop(stack)))
	{
		push(queue, token);
	}
	separate(queue, shunting, data);
}

void	getExpressions(char **data, t_shunting *shunting)
{
	shunting->indx = -1;
    while (data[++shunting->indx]) {
        if (data[shunting->indx][0] != '=') {
            if (data[shunting->indx][0] != '?'){
                convertToPostfix(ft_strsub(data[shunting->indx], 0
				, ft_strchr_indx(data[shunting->indx], '=')), shunting);
            }
        }
    }
    getValues(data, shunting);
}
