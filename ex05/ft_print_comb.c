#include <unistd.h>

void	print(char *str, int size)
{
	write(1, str, size);
	if (str[0] == '7' && str[1] == '8' && str[2] == '9')
		return ;
	write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	numbers[4];

	numbers[0] = '0';
	numbers[1] = '1';
	numbers[2] = '2';
	numbers[4] = '\0';
	while (numbers[0] <= '9')
	{
		while (numbers[1] <= '9')
		{
			while (numbers[2] <= '9')
			{
				print(numbers, 3);
				numbers[2]++;
			}
			numbers[1]++;
			numbers[2] = numbers[1] + 1;
		}
		numbers[1] = numbers[0] + 1;
		numbers[0]++;
	}
}
