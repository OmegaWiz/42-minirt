/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:19:51 by moonegg           #+#    #+#             */
/*   Updated: 2023/07/05 08:52:26 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void) argv;
	if (argc != 2)
		return (1);
	if (file_init(&vars, argv[1]) != 0)
		return (2);
	win_init(&vars);
	return (0);
}
