/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:00:48 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/17 16:38:13 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_win(t_cub3d **cub)
{
	ft_free_tab(cub[0]->map, NULL, NULL);
	free(cub[0]);
	//mlx_clear_window(cub[0]->mlx, cub[0]->win);
	//mlx_destroy_window(cub[0]->mlx, cub[0]->win);
	exit(0);
	return (0);
}

void	ft_load_sprite(t_cub3d **cub)
{
	int h;

	h = 250;
	cub[0]->spt1 = mlx_xpm_file_to_image(cub[0]->mlx, "./map/s1.xpm", &h, &h);
	cub[0]->spt2 = mlx_xpm_file_to_image(cub[0]->mlx, "./map/s2.xpm", &h, &h);
	cub[0]->spt3 = mlx_xpm_file_to_image(cub[0]->mlx, "./map/s3.xpm", &h, &h);
}

void	ft_cub3d(t_cub3d *cub)
{
	ft_load_sprite(&cub);
	ft_handle_keys(123, &cub);
	//ft_screan_display(cub);
	mlx_hook(cub->win, 17, 0, ft_close_win, &cub);
	mlx_hook(cub->win, 2, 0, ft_handle_keys, &cub);
	//printf("shot = %d\n", cub->shot);
	//mlx_hook(cub->win, 3, 0, ft_sprite, &cub);
	//mlx_hook(cub->win, 3, 0, ft_sprite, &cub);
	//mlx_key_hook(cub->win, ft_sprite_two, &cub);
	//mlx_hook(cub->win, 6, 0, ft_handle_mouse, &cub);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_cub3d *cub;

	cub = NULL;
	if (ft_parse_map_file(ac, av))
		return (1);
	cub = ft_initialize_struct(av[1], cub);
	if (cub == NULL)
		return (1);
	cub->mouse = 0;
	cub->shot = 0;
	ft_cub3d(&cub[0]);
	return (0);
}
