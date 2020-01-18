/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 13:52:08 by exam              #+#    #+#             */
/*   Updated: 2019/12/26 15:21:39 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex(unsigned char c)
{
	unsigned char	out;

	if (c >> 4 <= 9)
		out = (c >> 4) + '0';
	else
		out = (c >> 4) + 87;
	write(1, &out, 1);
	if ((c & 0x0F) <= 9)
		out = (c & 0x0F) + '0';
	else
		out = (c & 0x0F) + 87;
	write(1, &out, 1);
	return ;
}

void	print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			j;
	size_t			lines;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	lines = size / 16;
	if (size % 16)
		lines++;
	j = 0;
	while (j < lines)
	{
		i = 0;
		while (i < 16)
		{
			if (j * 16 + i < size)
				ft_puthex(ptr[j * 16 + i]);
			else
				write(1, "  ", 2);
			if (i % 2)
				write(1, " ", 1);
			i++;
		}
		i = 0;
		while ((i < 16) && (j * 16 + i < size))
		{
			if (ptr[j * 16 + i] > 31 && ptr[j * 16 + i] < 127)
				write(1, &ptr[j * 16 + i], 1);
			else
				write(1, ".", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
	return ;
}	
