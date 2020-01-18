/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:21:47 by exam              #+#    #+#             */
/*   Updated: 2019/12/19 15:11:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "biggest_pal.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int		ft_check_pal(char *str, int len)
{
	int	i;
	
	i = 0;
	while (i <= len - 1 - i)
	{
		if (str[i] != str[len - 1 - i])
			return (0);
		i++;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	int		len;
	int		str_len;
	int		i;
	int		n;
	char	*str;
	char	*ptr;

	if (argc == 2)
	{
		str = argv[1];
		str_len = ft_strlen(str);
		len = 1;
		ptr = str;
		i = 0;
		while (i < str_len)
		{
			n = len;
			while (i + n <= str_len)
			{
				if (ft_check_pal(&str[i], n))
				{
					ptr = &str[i];
					len = n;
				}
				n++;			
			}
			i++;
		}
		ptr[len] = '\0';
		ft_putstr(ptr);
	}
	ft_putstr("\n");
}
