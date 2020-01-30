/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:10:15 by exam              #+#    #+#             */
/*   Updated: 2020/01/30 12:51:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_pawn(char **brd, int size, int ky, int kx)
{
	if (ky < size && kx + 1 < size && brd[ky + 1][kx + 1] == 'P')
		return (1);
	if (ky < size && kx > 0 && brd[ky + 1][kx - 1] == 'P')
		return (1);
	return (0);
}

int	check_lines(char **brd, int size, int ky, int kx)
{
	int y;
	int x;

	y = 1;
	while (ky + y <= size && !(brd[ky + y][kx] == 'P' || brd[ky + y][kx] == 'B'))
	{
		if (brd[ky + y][kx] == 'R' || brd[ky + y][kx] == 'Q')
			return (1);
		y++;
	}
	y = 1;
	while (ky - y > 0 && !(brd[ky - y][kx] == 'P' || brd[ky - y][kx] == 'B'))
	{
		if (brd[ky - y][kx] == 'R' || brd[ky - y][kx] == 'Q')
			return (1);
		y++;
	}
	x = 1;
	while (kx + x < size && !(brd[ky][kx + x] == 'P' || brd[ky][kx + x] == 'B'))
	{
		if (brd[ky][kx + x] == 'R' || brd[ky][kx + x] == 'Q')
			return (1);
		x++;
	}
	x = 1;
	while (kx - x >= 0 && !(brd[ky][kx - x] == 'P' || brd[ky][kx - x] == 'B'))
	{
		if (brd[ky][kx - x] == 'R' || brd[ky][kx - x] == 'Q')
			return (1);
		x++;
	}
	return (0);
}

int	check_diag(char **brd, int size, int ky, int kx)
{
	int y;
	int x;

	y = 1;
	x = 1;
	while (ky + y <= size && kx + x < size && !(brd[ky + y][kx + x] == 'P' || brd[ky + y][kx + x] == 'R'))
	{
		if (brd[ky + y][kx + x] == 'B' || brd[ky + y][kx + x] == 'Q')
			return (1);
		y++;
		x++;
	}
	y = 1;
	x = 1;
	while (ky - y > 0 && kx - x >= 0 && !(brd[ky - y][kx - x] == 'P' || brd[ky - y][kx - x] == 'R'))
	{
		if (brd[ky - y][kx - x] == 'B' || brd[ky - y][kx - x] == 'Q')
			return (1);
		y++;
		x++;
	}
	y = 1;
	x = 1;
	while (ky - y > 0 && kx + x < size && !(brd[ky - y][kx + x] == 'P' || brd[ky - y][kx + x] == 'R'))
	{
		if (brd[ky - y][kx + x] == 'B' || brd[ky - y][kx + x] == 'Q')
			return (1);
		y++;
		x++;
	}
	y = 1;
	x = 1;
	while (ky + y <= size && kx - x >= 0 && !(brd[ky + y][kx - x] == 'P' || brd[ky + y][kx - x] == 'R'))
	{
		if (brd[ky + y][kx - x] == 'B' || brd[ky + y][kx - x] == 'Q')
			return (1);
		y++;
		x++;
	}
	return (0);
}

int	main(int argc, char **brd)
{
	int	size;
	int	i;
	int	j;
	int	kx;
	int ky;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	size = argc - 1;
	j = 1;
	while (j <= size)
	{
		i = 0;
		while (i < size)
		{
			if (brd[j][i] == 'K')
			{
				ky = j;
				kx = i;
			}
			i++;
		}
		j++;
	}
	if (check_pawn(brd, size, ky, kx))
	{
		write(1, "Success\n", 8);
		return (1);
	}
	if (check_lines(brd, size, ky, kx))
	{
		write(1, "Success\n", 8);
		return (1);	
	}
	if (check_diag(brd, size, ky, kx))
	{
		write(1, "Success\n", 8);
		return (1);	
	}
	write(1, "Fail\n", 5);
	return (1);
}
