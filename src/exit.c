/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:19:10 by stakan            #+#    #+#             */
/*   Updated: 2023/03/13 14:13:38 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
}

int	mouse_hook(int mousecode, t_data *data)
{
	err_msg("Exit Success");
	return (0);
}

void	exit_door(t_data *data)
{
	if (data->coin_collected == data->coin_count)
		err_msg("FINISH");
	else
	{
		ft_printf("Sorry, you can't exit.\n");
	}
}
