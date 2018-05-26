#include "../inc/exp_sys.h"

void	getQueries(t_shunting *shunting) {
    int		i;
    int		counter;
    
	i = -1;
	counter = -1;
	while (shunting->data[++i])
	{
		if (shunting->data[i][0] == '?')
			counter++;
	}
	if (!(shunting->queries = ft_strnew_point(counter))) return;
	i = -1;
	counter = -1;
	while (shunting->data[++i])
	{
		if (shunting->data[i][0] == '?')
			shunting->queries[++counter] = ft_strdup(shunting->data[i] + 1);
	}
}

bool	**booleanValue(t_shunting *shunting) {
    int		i;
    int		k;
    int		f;
    bool	**boolValue;

	i = -1;
	boolValue = (bool **) malloc(ft_strlen_point(shunting->facts) * sizeof(bool));
	while (shunting->facts[++i]) {
		k = -1;
		f = 0;
		boolValue[i] = (bool *)malloc(ft_strlen(shunting->operands) * sizeof(bool));
		while (shunting->operands[++k]) {
			if (shunting->operands[k] == shunting->facts[i][f]){
				boolValue[i][k] = 1;
				f++;
			} else {
				boolValue[i][k] = 0;
			}
		}
	}
	return (boolValue);
}

int		main(int argc, char **argv)
{
	t_shunting	shunting;
	int			fd;
	int			iterate;
	int			i;

    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        if (fd > 0) {
			shunting._sindx = 0;
            getData(fd, argv[1], &shunting);
			getFacts(&shunting);
            getValues(shunting.data, &shunting);
            getRightOp(shunting.data, &shunting);
            getRightValues(&shunting);
			i = -1;
			iterate = 1;
			while (shunting.rightOperands[++i]) {
				if (ft_strchr_indx(shunting.operands, shunting.rightOperands[i]) > -1) {
					iterate += ft_strchr_indx(shunting.operands, shunting.rightOperands[i]);
					break ;
				}
			}
			shunting.answers = createBoolStack(shunting._sindx);
			shunting.booleanVal = booleanValue(&shunting);
			shunting.q = (int *)malloc(sizeof(ft_strlen(shunting.queries[0])));
			int i;
			shunting.factIndx = -1;
			while (shunting.facts[++shunting.factIndx]) {
				getExpressions(shunting.data, &shunting);
				i = -1;
				if (iterate >= 1) {
					while (!isEmpty(shunting.answers)) {
						++i;
						ft_putchar(shunting.rightOperands[i]);
						ft_putstr(" - ");
						popBool(shunting.answers) ? ft_putstr("true") : ft_putstr("false");
						ft_putchar('\n');
					}
				}
				ft_putchar('\n');
			}	
        }
        else
            getError(FILE_ERROR);
    }
    else {
        getError(USAGE_ERROR);
        exit(1);
    }
    return (0);
}
