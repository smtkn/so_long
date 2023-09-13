/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:20:02 by stakan            #+#    #+#             */
/*   Updated: 2023/03/13 10:09:32 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_control(t_data *data)
{
	int		fd;
	char	*line;
	int		y;
	int		x;

	y = 0;
	fd = open(data->map_tmp, O_RDONLY);
	line = get_next_line(fd);
	x = ft_strlen(line);
	while (1)
	{
		free(line);
		y++;
		line = get_next_line(fd);
		if (line[0] == '\0')
			break ;
		if (x != ft_strlen(line) && line[0] != '\0')
			err_msg("Error\nMap is not rectangular");
	}
	if (!line)
		free(line);
	data->map_height = y;
	data->map_width = x - 1;
	close (fd);
}

void	wall_control(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_width)
		if (data->map[0][x++] != '1')
			err_msg("Error\nThe map has to be surrounded by walls");
	while (y < data->map_height)
	{
		if (data->map[y][0] != '1' || data->map[y][data->map_width - 1] != '1')
			err_msg("Error\nThe map has to be surrounded by walls");
		y++;
	}
	x = 0;
	while (x < data->map_width)
		if (data->map[data->map_height - 1][x++] != '1')
			err_msg("Error\nThe map has to be surrounded by walls");
}

void	min_element_control(t_data *data)
{
	if (data->player_count != 1)
		err_msg("Error\nThere must be 1 player on the map");
	if (data->exit_count != 1)
		err_msg("Error\nThere must be 1 exit on the map");
	if (data->coin_count < 1)
		err_msg("Error\nMust have at least 1 collectible on the map");
	if (data->wall_count < 9)
		err_msg("Error\nWrong on the map");
	if (data->unwanted_character_count != 0)
		err_msg("Error\nThe map must contain only [0,1,E,P,C] characters");
}
