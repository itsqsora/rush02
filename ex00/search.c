/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sorungta@42bangkok.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:18:17 by mac               #+#    #+#             */
/*   Updated: 2022/07/31 20:00:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
unsigned int	ft_atoi(char *str);

void			printvalue(char *dict);

/*
 * a function that search for a value in .dict file.
 * otherwise, return dict error if it doesn't allow you
 * to reach the asked value.
 */
void	search(unsigned int n, char **dict, int *init)
{
	int	line;
	int	found;

	line = 0;
	found = 0;
	if (*init != 0)
		write(1, " ", 1);
	while (dict[line++])
	{
		if (ft_atoi(dict[line - 1]) == n)
		{
			found = 1;
			*init = *init + 1;
			printvalue(dict[line - 1]);
			break ;
		}
	}
	if (!found)
		write(1, "Dict Error\n", 11);
}
