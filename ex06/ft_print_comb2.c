/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:21:36 by coder             #+#    #+#             */
/*   Updated: 2022/02/05 22:44:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_number[5];

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (0);
	return (1);
}

void	ft_print(char *ptr)
{
	write(1, ptr, 1);
	write(1, (ptr + 1), 1);
	write(1, " ", 1);
	write(1, (ptr + 2), 1);
	write(1, (ptr + 3), 1);
	if (!(ft_strcmp(ptr, "9899")))
		write(1, ", ", 2);
}

void	init_array(void)
{
	g_number[0] = '0';
	g_number[1] = '0';
	g_number[2] = '0';
	g_number[3] = '1';
	g_number[4] = '\0';
}

void	ft_print_comb2(void)
{
	init_array();
	while (g_number[0] <= '9')
	{
		while (g_number[1] <= '9')
		{
			while (g_number[2] <= '9')
			{
				while (g_number[3] <= '9')
				{
					ft_print(g_number);
					g_number[3]++;
				}
				g_number[2]++;
				g_number[3] = g_number[1];
			}
			g_number[1]++;
			g_number[2] = g_number[0];
			g_number[3] = g_number[1] + 1;
		}
		g_number[0]++;
		g_number[1] = '0';
		g_number[2] = g_number[1];
		g_number[3] = g_number[2] + 1;
	}
}
