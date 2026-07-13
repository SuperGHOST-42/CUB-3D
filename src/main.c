/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:22:35 by figomes           #+#    #+#             */
/*   Updated: 2026/07/13 14:03:17 by figomes          ###   ########.fr       */
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
	trim_end_empty_lines(game.full_map);
	print_game(&game);
	validade_map(&game);
	///// GHOST //////
	//init_player(&game);
	//init_mlx(&game);
	clean_game(&game);
	return (0);
}
