/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:51:34 by mressier          #+#    #+#             */
/*   Updated: 2017/10/29 03:57:54 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int		internal_get_filename_on_arg(int ac, char **av,
					char **out_filename)
{
	if (ac != 2)
		return (error(EMPTYARGV, EXIT_FAILURE));
	*out_filename = av[1];
	return (EXIT_SUCCESS);
}

int				main(int ac, char **av)
{
	char		*filename;
	char		*file_content;
	t_asm		asm_file_content;

	asm_file_content.label_list = NULL;
	if (internal_get_filename_on_arg(ac, av, &filename) == EXIT_FAILURE)
		return (asm_usage());
	if (asm_get_file_content(filename, &file_content) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (asm_get_asm_from_file_content(file_content,
			&asm_file_content) == EXIT_FAILURE)
	{
		ft_memdel((void **)&file_content);
		asm_t_asm_del_content(asm_file_content);
		return (EXIT_FAILURE);
	}
	asm_t_asm_instruct_init_list(&asm_file_content);
	asm_t_label_display_list(asm_file_content.label_list);
	if (asm_write_asm_to_file(&asm_file_content, filename) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	asm_t_label_display_list(asm_file_content.label_list);
	asm_t_asm_del_content(asm_file_content);
	ft_memdel((void **)&file_content);
	return (EXIT_SUCCESS);
}
