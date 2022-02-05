#include <unistd.h>

int		g_total_comb;
int		g_control;
char	g_numbers[10]; 
char	g_comb[3];

int	calc_comb(int digits, int n)
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

void	ft_print(int start, int end, int index, int c)
{
	int	i;

	i = 0;
	if (index == c)
	{
		while (i < c)
		{
			ft_display(g_comb[i]);
			i++;
		}
		if (g_control < g_total_comb)
		{
			ft_display(',');
			ft_display(' ');
			g_control++;
		}
		return ;
	}
	i = start;
	while (i <= end && (end - i + 1) >= (c - index))
	{
		g_comb[index] = g_numbers[i];
		ft_print(i + 1, end, index + 1, c);
		i++;
	}
}

void	ft_print_combn(int n)
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
	g_control = 1;
	g_total_comb = calc_comb(10, n);
	ft_print(0, 9, 0, n);
}
