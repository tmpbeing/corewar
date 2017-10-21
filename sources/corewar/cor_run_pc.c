/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_run_pc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:22:54 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/21 17:53:11 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

int		run_pc(t_game *game, t_cycle *c)
{
	t_pc	*pc;

	pc = game->pcs;
	while (pc != 0)
	{
		if (c->current >= pc->last_live + c->to_die)
			;//kill pc
		else if (pc->wait == 0)
		{
			//(pc->cmd)(game, pc); //do cmd et addr = next addr
			//(pc->cmd) = next cmd;
			pc->wait = get_wait((game->arena)[pc->addr]) - 1;
		}
		else
			(pc->wait)--;
		pc = pc->next;
	}
	return (0);
}