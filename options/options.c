/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:07:05 by exam              #+#    #+#             */
/*   Updated: 2020/01/18 13:21:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	str[] = "00000000 00000000 00000000 00000000\n";
	char	*sample = "hhhhhhzy xwvutsrq ponmlkji hgfedcba";
	int		i;
	int		n;

	if (argc < 2)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}
	while (--argc)
		if (argv[argc][0] == '-')
		{
			i = 1;
			while (argv[argc][i])
			{
				
				if (argv[argc][i] == 'h')
				{
					write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
					return (0);
				}
				n = 0;
				if ('a' <= argv[argc][i] && argv[argc][i] <= 'z')
					while (n < 35)
					{
						if (sample[n] == argv[argc][i])
							str[n] = '1';
						n++;
					}
				else
				{
					write(1, "Invalid Option\n", 15);
					return (0);
				}
				i++;
			}
		}
	write(1, str, 36);
	return (0);
}
