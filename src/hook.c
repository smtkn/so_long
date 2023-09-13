/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:19:27 by stakan            #+#    #+#             */
/*   Updated: 2023/03/19 10:50:04 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 2, key_hook, data);
	mlx_hook(data->win, 17, 1L << 2, mouse_hook, data);
}

static void	step_count(t_data *data)
{
	data->step_count++;
	ft_printf("Step: %d\r", data->step_count);
	mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
		0 * IMG_SIZE, 0 * IMG_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
		1 * IMG_SIZE, 0 * IMG_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
		2 * IMG_SIZE, 0 * IMG_SIZE);
	mlx_string_put(data->mlx, data->win, 5, 30,
		0x00FF0000, "Player Steps: ");
	mlx_string_put(data->mlx, data->win, 95, 30,
		0x00FF0000, ft_itoa(data->step_count));
}

static int	real_walking(int y, int x, t_data *data)
{
	if (data->map[data->player_y + y][data->player_x + x] == '1')
		return (0);
	else if (data->map[data->player_y + y][data->player_x + x] == 'C')
	{
		data->map[data->player_y + y][data->player_x + x] = '0';
		data->coin_collected++;
	}
	else if (data->map[data->player_y + y][data->player_x + x] == 'E')
	{
		exit_door(data);
		return (2);
	}
	return (1);
}

static int	walking(int keycode, t_data *data, int x)
{
	int (val);
	if (keycode == 2 || keycode == 0)
	{
		val = real_walking(0, x, data);
		if (val == 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
			data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
		data->player_x += x;
		animationy(data, keycode);
		animationx(data, keycode);
	}
	if (keycode == 13 || keycode == 1)
	{
		if (real_walking(-x, 0, data) == 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
			data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
		data->player_y -= x;
		animationy(data, keycode);
		animationx(data, keycode);
	}
	step_count(data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		err_msg("Exit Success");
	else if (keycode == 2 || keycode == 13)
		walking(keycode, data, 1);
	else if (keycode == 0 || keycode == 1)
		walking(keycode, data, -1);
	return (0);
}
