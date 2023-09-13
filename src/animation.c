/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:50:50 by stakan            #+#    #+#             */
/*   Updated: 2023/03/19 15:08:55 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animationx(t_data *data, int keycode)
{
	static int (i);
	if (keycode == 2)
	{
		walking_continue(data);
		if (i % 2 == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->img.character,
				data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
		if (i % 2 == 1)
			mlx_put_image_to_window(data->mlx, data->win, data->img.characterr,
				data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	}
	else if (keycode == 0)
	{	
		walking_continue(data);
		if (i % 2 == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->img.characterl,
				data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
		if (i % 2 == 1)
			mlx_put_image_to_window(data->mlx, data->win, data->img.characterll,
				data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	}
	i++;
}

void	animationy(t_data *data, int keycode)
{
	static int (j);
	walking_continue(data);
	if (keycode == 13)
	{
		walking_continue(data);
		if (j % 2 == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->img.characteru,
				data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
		if (j % 2 == 1)
			mlx_put_image_to_window(data->mlx, data->win, data->img.characteruu,
				data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	}
	else if (keycode == 1)
	{
		walking_continue(data);
		if (j % 2 == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->img.characterd,
				data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
		if (j % 2 == 1)
			mlx_put_image_to_window(data->mlx, data->win, data->img.characterdd,
				data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	}
	j++;
}

void	walking_continue(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
		data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.door,
		data->exit_x * IMG_SIZE, data->exit_y * IMG_SIZE);
}
