/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:31:07 by arpereir          #+#    #+#             */
/*   Updated: 2026/05/15 17:50:37 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_game	game;
	char	*test_map[] = 
					{
					"1111111111",
					"1000000001",
					"1001000001",
					"1000000001",
					"100000N001",
					"1111111111",
					NULL
					};
	ft_bzero(&game, sizeof(t_game));
	game.map = dup_map(test_map);

	init_player(&game);
	raycast(&game);
	init_mlx(&game);
	
	return (0);
}
