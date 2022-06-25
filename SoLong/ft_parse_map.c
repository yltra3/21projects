/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:29:03 by clornel           #+#    #+#             */
/*   Updated: 2022/04/14 19:29:06 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_map(t_gmap *gmap)
{
	mlx_get_screen_size(&gmap->max_width, &gmap->max_height);
	gmap->max_width = gmap->max_width / PIC_SIZE - 1;
	gmap->max_height = gmap->max_height / PIC_SIZE - 1;
	gmap->width = 0;
	gmap->height = 0;
	gmap->hero = 0;
	gmap->coin = 0;
	gmap->earn_coins = 0;
	gmap->moves = 0;
	gmap->field = NULL;
	gmap->data->timer = 0;
	gmap->exits = 0;
}

static void	ft_field_check(t_gmap *gmap, size_t i, size_t j)
{
	if (ft_chars_count(gmap->field[gmap->height - 1], WALL) != (int)gmap->width
		|| ft_chars_count(gmap->field[0], WALL) != (int)gmap->width)
		ft_err_exit("field's border is not correct");
	i = 0;
	while (++i < gmap->height - 1 && gmap->hero < 2)
	{
		if (gmap->field[i][0] != WALL || gmap->field[i][gmap->width - 1]
			!= WALL)
			ft_err_exit("left or rigth field's border issue");
		gmap->hero += ft_chars_count(gmap->field[i], HERO);
		gmap->exits += ft_chars_count(gmap->field[i], EXIT);
		gmap->coin += ft_chars_count(gmap->field[i], COIN);
		j = 0;
		while (++j < gmap->width - 2)
		{
			if (!ft_check_symbols(gmap->field[i][j], SYMBOLS))
				ft_err_exit("incorrect symbol in the map");
			if (gmap->field[i][j] == 'K' && !gmap->data->bonus)
				gmap->field[i][j] = '0';
		}
	}
	if (gmap->hero != 1)
		ft_err_exit("check count of players in the map");
}

static void	ft_map_check(int fd, t_gmap *gmap, int gnl, int fl)
{
	char	*line;
	size_t	len;

	line = NULL;
	while (gnl)
	{
		gnl = ft_gnl(fd, &line);
		if (gnl < 0)
			ft_err_exit("gnl error");
		len = ft_strlen_m(line, 0);
		if ((int)len > gmap->max_width)
			ft_err_exit("map width too long for your screen");
		if (!gmap->width)
			gmap->width = len;
		if (!len)
			fl = 1;
		if (len && (fl || gmap->width != len))
			ft_err_exit("different line lenghts in the map");
		gmap->height += !fl;
		if ((int)gmap->height > gmap->max_height)
			ft_err_exit("map height too tall for your screen");
		free(line);
	}
	close(fd);
}

static void	ft_field_fill(char *file, t_gmap *gmap)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_err_exit("can't open file(open)");
	gmap->field = malloc(sizeof(char *) * (gmap->height + 1));
	if (!gmap->field)
		ft_err_exit("can't allocate memory(malloc)");
	line = NULL;
	i = 0;
	while (i < gmap->height)
	{
		if (ft_gnl(fd, &line) < 0)
			ft_err_exit("get_next_line error");
		gmap->field[i] = line;
		line = NULL;
		i++;
	}
	gmap->field[i] = NULL;
	close(fd);
}

int	ft_parse_map(char **argv, t_gmap *gmap)
{
	int	f_len;
	int	fd;

	f_len = ft_strlen_m(argv[1], 0);
	if (f_len < 4 || ft_strncmp(argv[1] + f_len - 4, ".ber", 5))
		ft_err_exit("map .format issue");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_err_exit("map read issue");
	ft_init_map(gmap);
	ft_map_check(fd, gmap, 1, 0);
	if (!gmap->height)
		ft_err_exit("empty map");
	ft_field_fill(argv[1], gmap);
	ft_field_check(gmap, 0, 0);
	if (!gmap->exits)
		ft_err_exit("no exits");
	if (!gmap->coin)
		ft_err_exit("no collectibles");
	return (1);
}
