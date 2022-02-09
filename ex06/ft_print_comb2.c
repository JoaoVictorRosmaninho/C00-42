#include <unistd.h>

void	clear(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = '0';
		i++;
	}
}

void	ft_print(char *str)
{
	if ((str[0] == '9' && str[1] == '8'))
	{
		write(1, str, 1);
		write(1, (str + 1), 1);
		write(1, " ", 1);
		write(1, (str + 2), 1);
		write(1, (str + 3), 1);
	}
	else
	{
		write(1, str, 1);
		write(1, (str + 1), 1);
		write(1, " ", 1);
		write(1, (str + 2), 1);
		write(1, (str + 3), 1);
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb2(void)
{
	char	str[4];

	clear(str, 4);
	while (str[0] <= '9')
	{
		while (str[1] <= '9')
		{
			str[2] = str[0];
			str[3] = str[1] + 1;
			while (str[2] <= '9')
			{
				while (str[3] <= '9')
				{
					ft_print(str);
					str[3]++;
				}
			str[2]++;
			str[3] = '0';
			}
			str[1]++;
		}
	str[0]++;
	str[1] = '0';
	}
}
