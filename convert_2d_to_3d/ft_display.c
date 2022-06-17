/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:41:22 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/17 16:58:10 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    //printf("%d %d\n",img->line_len,img->bpp);
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

// last and correct version of display

void	ft_camera(t_cub3d **cub)
{
	double	dev;
	int		dec;

	dev = (double) WIDTH / 1700;
	dec = (int) WIDTH / 1700;
	if ((double) dec < dev)
		cub[0]->cmr = dec + 1;
	else
		cub[0]->cmr = dec;
}

void	ft_screan_display(t_cub3d *cub)
{
	int i;
	int	j;
	int	mid;
	int	index;

	ft_camera(&cub);
	img.mlx_ptr = cub->mlx;
	img.mlx_win = cub->win;
	img.mlx_img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.mlx_img,&img.bpp,&img.line_len,&img.endien);
	index = 0;
	j = 0;
	while (index < 1699 && j < WIDTH - 1)
	{
		i = 0;
		mid = cub->ray_height[index][2] / 2;
		while (i < HEIGHT)
		{
			if (i < ((HEIGHT / 2) - mid))
				img_pix_put(&img,j,i,0);
			else if ((i >= ((HEIGHT / 2) - mid)) && (i <= ((HEIGHT / 2) + mid)))
			{
				if (cub->ray_height[index][3] == 1)
					img_pix_put(&img,j,i,16711680);
				else if (cub->ray_height[index][3] == 2)
					img_pix_put(&img,j,i,65280);
				else if (cub->ray_height[index][3] == 3)
					img_pix_put(&img,j,i,255);
				else if (cub->ray_height[index][3] == 4)
					img_pix_put(&img,j,i,16777116);
			}
			else if (i > ((HEIGHT / 2) + mid))
				img_pix_put(&img,j,i,16777215);
			i++;
		}
		//if (j % cub->cmr == 0)
			index++;
		j++;
	}
}
