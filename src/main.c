/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:22:35 by figomes           #+#    #+#             */
/*   Updated: 2026/07/01 01:25:02 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	
	check_command(argc, argv[1]);
	init_game(&game);
	init_map(argv[1], &game);
	validate_config(&game);
	//print_game(&game);
	///// GHOST //////
	init_player(&game);
	init_mlx(&game);
	return (0);
}
