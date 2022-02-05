#include <unistd.h>

#define SIZE 3

int		g_total_comb;
int		g_control;
char	g_numbers[10];
char	g_comb[3];

int	calc_g_comb(int digits, int n)
{
	int	aux;
	int	upper;
	int	down;

	aux = digits;
	upper = 1;
	down = 1;
	while (aux > (digits - n))
	{
		upper *= aux;
		aux--;
	}
	while (n >= 1)
	{
		down *= n;
		n--;
	}
	return (upper / down);
}

void	ft_display(char ch)
{
	write(1, &ch, 1);
}

void	ft_print(int start, int end, int index)
{
	int	i;

	i = 0;
	if (index == SIZE)
	{
		while (i < SIZE)
		{
			ft_display(g_comb[i]);
			i++;
		}
		if (g_control < g_total_comb)
		{
			ft_display(' ');
			ft_display(',');
			g_control++;
		}
		return ;
	}
	i = start;
	while ((i <= end) && (end - i + 1) >= (SIZE - index))
	{
		g_comb[index] = g_numbers[i];
		ft_print(i + 1, end, index + 1);
		i++;
	}
}

void	ft_print_comb(void)
{
	g_numbers[0] = '0';
	g_numbers[1] = '1';
	g_numbers[2] = '2';
	g_numbers[3] = '3';
	g_numbers[4] = '4';
	g_numbers[5] = '5';
	g_numbers[6] = '6';
	g_numbers[7] = '7';
	g_numbers[8] = '8';
	g_numbers[9] = '9';
	g_total_comb = calc_g_comb(10, 3);
	g_control = 1;
	ft_print(0, 9, 0);
}
