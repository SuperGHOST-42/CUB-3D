/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:31:07 by arpereir          #+#    #+#             */
/*   Updated: 2026/05/03 17:42:28 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int main(int argc, char **argv)
{
	t_game *game;
	char	*map[] = 
	{
	"1111111111",
	"1000000001",
	"1001000001",
	"1000000001",
	"100000N001",
	"1111111111",
	NULL
	};

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_bzero(game, sizeof(game));

	free(game);
	return (0);	
}
