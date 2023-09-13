/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:19:45 by stakan            #+#    #+#             */
/*   Updated: 2023/03/13 14:56:37 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_create(t_data *data)
{
	data->img.bg = mlx_xpm_file_to_image(data->mlx, "img/background-wall.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.coin = mlx_xpm_file_to_image(data->mlx, "img/bullet-right.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.door = mlx_xpm_file_to_image(data->mlx, "img/door.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.character = mlx_xpm_file_to_image(data->mlx, "img/mach-right.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.characterr = mlx_xpm_file_to_image(data->mlx, "img/machright.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.characterl = mlx_xpm_file_to_image(data->mlx, "img/mach-left.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.characterll = mlx_xpm_file_to_image(data->mlx, "img/machleft.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.characteru = mlx_xpm_file_to_image(data->mlx, "img/mach-up.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.characteruu = mlx_xpm_file_to_image(data->mlx, "img/machup.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.characterd = mlx_xpm_file_to_image(data->mlx, "img/mach-down.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.characterdd = mlx_xpm_file_to_image(data->mlx, "img/machdown.xpm",
			&data->img.img_w, &data->img.img_h);
}

void	map_read(t_data *data)
{
	int		fd;
	int		i;
	int		j;
	char	*area;

	i = 0;
	j = 0;
	fd = open(data->map_tmp, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * data->map_height);
	while (i < data->map_height)
	{
		j = 0;
		area = get_next_line(fd);
		data->map[i] = (char *)malloc(sizeof(char *) * data->map_width);
		if (area == 0)
			break ;
		while (j < data->map_width)
		{
			data->map[i][j] = area[j];
			j++;
		}
		data->map[i][j] = '\0';
		i++;
		free(area);
	}
}

static void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_width * IMG_SIZE,
			data->map_height * IMG_SIZE, "SoLong");
	data->coin_count = 0;
	data->coin_collected = 0;
	data->step_count = 0;
	data->exit_count = 0;
	data->wall_count = 0;
	data->player_count = 0;
	data->unwanted_character_count = 0;
}

void	mlx_create(t_data *data)
{
	data_init(data);
	image_create(data);
	map_read(data);
	map_bacgraund_put(data);
	map_create(data);
	wall_control(data);
	min_element_control(data);
	placeholder(data, data->exit_x, data->exit_y);
	if (data->i_map.read_count != data->coin_count + 1)
		err_msg("Error\n>>>The map is wrong");
	hook(data);
	mlx_loop(data->mlx);
}
