/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sorungta@42bangkok.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:50:32 by mac               #+#    #+#             */
/*   Updated: 2022/07/31 19:52:59 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checkerror(int argc)
{
	if (argc != 2 && argc != 3) // if the passing argument values are not 3 nor 2, return error.
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
		return (1);
}
