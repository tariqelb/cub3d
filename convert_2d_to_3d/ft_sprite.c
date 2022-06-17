/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:09:08 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/16 21:25:31 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_sprite(int key, t_cub3d **cub)
{
	int i = 0;
	
	if (key == 49)
	{
		while (i < 100)
		{	
			printf("Hello from mlx_loop_hook 1 %d\n", cub[0]->shot);
			mlx_clear_window(cub[0]->mlx, cub[0]->win);
			mlx_put_image_to_window(img.mlx_ptr, img.mlx_win, img.mlx_img, 0, 0);
			mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->spt1, (WIDTH / 2) - 125, HEIGHT - 250);
			cub[0]->shot = 1;
			i++;
		}
		i = 0;
		while (i < 100)	
		{
			printf("Hello from mlx_loop_hook 2 %d\n", cub[0]->shot);
			mlx_clear_window(cub[0]->mlx, cub[0]->win);
			mlx_put_image_to_window(img.mlx_ptr, img.mlx_win, img.mlx_img, 0, 0);
			mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->spt2, (WIDTH / 2) - 125, HEIGHT - 250);
			cub[0]->shot = 2;
			i++;
		}
		i = 0;
		while (i < 100)
		{
			printf("Hello from mlx_loop_hook 3 %d\n", cub[0]->shot);
			mlx_clear_window(cub[0]->mlx, cub[0]->win);
			mlx_put_image_to_window(img.mlx_ptr, img.mlx_win, img.mlx_img, 0, 0);
			mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->spt3, (WIDTH / 2) - 125, HEIGHT - 250);
			cub[0]->shot = 0;
			i++;
		}
	}
   return (0);	
}

int	ft_sprite_two(int key, t_cub3d **cub)
{
	if (key == 49 && cub[0]->shot == 0)
	{
		printf("Hello from mlx_loop_hook 1 %d\n", cub[0]->shot);
		mlx_clear_window(cub[0]->mlx, cub[0]->win);
		mlx_put_image_to_window(img.mlx_ptr, img.mlx_win, img.mlx_img, 0, 0);
		mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->spt1, (WIDTH / 2) - 125, HEIGHT - 250);
		cub[0]->shot = 1;
	}
   return (0);	
}
