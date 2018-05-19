#include "../inc/exp_sys.h"

void    getQueries(t_shunting *shunting) {
    int     i;
    int     counter;
    
    i = -1;
    counter = -1;
    while (shunting->data[++i]) {
        if (shunting->data[i][0] == '?')
            counter++;
    }
    if (!(shunting->queries = ft_strnew_point(counter))) return;
    i = -1;
    counter = -1;
    while (shunting->data[++i]) {
        if (shunting->data[i][0] == '?')
            shunting->queries[++counter] = ft_strdup(shunting->data[i]);
    }
}

bool **booleanValue(t_shunting *shunting) {
    int i;
    int k;
    int f;
    bool **boolValue;

    i = -1;
    boolValue = (bool **) malloc(ft_strlen_point(shunting->facts) * sizeof(bool));
    while (shunting->facts[++i]) {
        k = -1;
        f = 0;
        boolValue[i] = (bool *)malloc(ft_strlen(shunting->operands) * sizeof(bool));
        while (shunting->operands[++k]) {
            if (shunting->operands[k] == shunting->facts[i][f]) {
                boolValue[i][k] = true;
                f++;
            } else {
                boolValue[i][k] = false;
            }
        }
    }
    return (boolValue);
}

int     main(int argc, char **argv) {
    t_shunting  shunting;
    int         fd;

    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        if (fd > 0) {
            getData(fd, argv[1], &shunting);
            getFacts(&shunting);
            getValues(shunting.data, &shunting);
            shunting.factIndx = -1;
            while (shunting.facts[++shunting.factIndx]) {
                shunting.booleanVal = booleanValue(&shunting);
                getExpressions(shunting.data, &shunting);
                break ;
            }
            getRightOp(shunting.data, &shunting);
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
