
void    get_err(int err_num)
{
    if (err_num == 1)
        ft_putendl("\x1b[31m)Oops! The file you tried to access is not valid or does not exist!\x1b[0m");
    else if (err_num == 2)
        ft_putendl("\x1b[31mOops! The format used is incorrect!\x1b[0m");
    else
        ft_putendl("\x1b[31mOops! There seems to be an error!\x1b[0m");
}