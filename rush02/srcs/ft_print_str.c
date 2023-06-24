#include<unistd.h>

void	ft_print_str(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}