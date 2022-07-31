/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sorungta@42bangkok.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:16:03 by mac               #+#    #+#             */
/*   Updated: 2022/07/31 19:54:11 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	a function to check writespaces
 */

int	is_writespace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	nbr;
	int				i;

	nbr = 0;
	i = is_writespace(str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i++] - 48);
	}
	return (nbr);
}
