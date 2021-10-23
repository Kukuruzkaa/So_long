#include "so_long.h"

void    ft_file_error(int fd, char *file)
{
    if (fd < 0 || ft_check_extention(file) == 0)
    {
        ft_putstr_fd("Error : not valid file extention\n", 2);
        exit(0);
    }
}

void    ft_error_output(t_data *data, int err)
{
    if (err == 1)
        ft_putstr_fd("Error : not valid map => not rectangular\n", 2);
    else if (err == 2)
        ft_putstr_fd("Error : not valid map => not closed map\n", 2);
    else if (err == 3)
        ft_putstr_fd("Error : not valid map => not closed wall\n", 2);
    else if (err == 4)
        ft_putstr_fd("Error : not valid map => not allowed character\n", 2);
    else if (err == 5)
        ft_putstr_fd("Error : not valid map => not enough game elements\n", 2);
    ft_free_data_and_exit(data);
}
