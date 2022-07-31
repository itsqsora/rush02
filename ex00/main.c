/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sorungta@42bangkok.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:17:51 by mac               #+#    #+#             */
/*   Updated: 2022/07/31 19:57:44 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		checkerror(int argc);
int		checkargv(char *argv);
void	toconverter(char *nbr, char *path);

int	main(int argc, char **argv)
{
	char	*path;

	path = "numbers.dict"; // we can change to another language dict here
	if (checkerror(argc))
	{
		if (argc == 2)
		{
			if (checkargv(argv[1]))
				toconverter(argv[1], path);
		}
		if (argc == 3)
		{
			if (checkargv(argv[2]))
			{
				path = argv[1];
				toconverter(argv[2], path);
			}
		}
	}
	return (0);
}
