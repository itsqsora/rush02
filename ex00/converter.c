/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvachira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:22:12 by nvachira          #+#    #+#             */
/*   Updated: 2022/07/31 19:50:49 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	setfree(char **dict);
char	**dict_init(char *dictpath);
void	search(unsigned int n, char **dict, int *init);
void	spliter(unsigned int input, char **dict, int *init);
void	splitter2(unsigned int input, char **dict, int *init);
int		ft_atoi(char *str);

void	check_input(unsigned int input, char **dict)
{
	int	init;

	init = 0;
	if (input < 0 || input > 4294967295)
		write(1, "Error\n", 6);
	else
		spliter(input, dict, &init);
}

void	converter(char *str, char **dict)
{
	unsigned int	input;

	input = ft_atoi(str);
	check_input(input, dict);
}

void	spliter(unsigned int input, char **dict, int *init)
{
	if (input >= 0 && input <= 9)
	{
		search(input, dict, init);
		return ;
	}
	if (input >= 10 && input <= 20)
	{
		search(input, dict, init);
		return ;
	}
	if (input >= 1000000)
	{
		spliter(input / 1000000, dict, init);
		search(1000000, dict, init);
		input = input % 1000000;
	}
	if (input >= 10000)
	{
		spliter(input / 1000, dict, init);
		search(1000, dict, init);
		input = input % 1000;
	}
	splitter2(input, dict, init);
}

void	splitter2(unsigned int input, char **dict, int *init)
{
	if (input >= 1000)
	{
		search(input / 1000, dict, init);
		search(1000, dict, init);
		input = input % 1000;
	}
	if (input >= 100)
	{
		search(input / 100, dict, init);
		search(100, dict, init);
		input = input % 100;
	}
	if (input > 20)
	{
		search((input / 10) * 10, dict, init);
		search(input % 10, dict, init);
	}
	else if (input != 0)
		spliter(input, dict, init);
}

void	toconverter(char *nbr, char *path)
{
	char	**dict;

	dict = dict_init(path);
	converter(nbr, dict);
	setfree(dict);
	write(1, "\n", 1);
}
