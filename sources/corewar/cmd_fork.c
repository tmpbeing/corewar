/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:40:44 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/23 19:09:53 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		fork_cpy(t_game *game, t_pc *pc)
{
	t_pc	*fork;

	fork = (t_pc *)malloc(sizeof(t_pc));
	if (!fork)
		return (error(MALLOC_FAILED, -1));
	fork = ft_memcpy(fork, pc, sizeof(t_pc));
	fork->next = pc->next;
	pc->next = fork;
	fork->addr = ((fork->addr + 3) % MEM_SIZE);
	fork->cmd = get_cmd((game->arena)[fork->addr]);
	fork->wait = get_wait((game->arena)[fork->addr]);
	return (0);
}

int		cmd_fork(t_game *game, t_pc *pc, t_cycle *cycle)
{
	(void)cycle;
	if (fork_cpy(game, pc) == -1)
		return (-1);
	pc->addr += read_nb(game->arena, pc->addr + 1, 2) % IDX_MOD;
	pc->addr = pc->addr % MEM_SIZE;
	return (pc->addr);
}