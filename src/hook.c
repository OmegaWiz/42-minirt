/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonegg <moonegg@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:14:16 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/03 16:12:10 by moonegg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	close_x(void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	do_none(void *data)
{
	(void) data;
	return (0);
}
