/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_asm_instruct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:33:34 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/23 12:25:28 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

t_asm_instruct		*asm_t_asm_instruct_new(void)
{
	t_asm_instruct	*new;

	new = (t_asm_instruct *)ft_memalloc(sizeof(t_asm_instruct));
	return (new);
}

t_asm_instruct		*create_asm_instruct(void (*fill)(t_asm_instruct*, t_instruct*), t_instruct *target)
{
	t_asm_instruct	*new;

	new = asm_t_asm_instruct_new();
	fill(new, target);
	return (new);
}
