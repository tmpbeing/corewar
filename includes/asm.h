/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:44:13 by mressier          #+#    #+#             */
/*   Updated: 2017/10/20 15:44:22 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"

# include <stdlib.h>

# define LABEL_LENGTH_MAX		128
# define INSTRUCT_LENGTH_MAX 	5
# define PARAM_MAX				3

/*
** ASM_INSTRUCT
*/

typedef struct				s_asm_instruct
{
	char					op_code;
	char					param_code;

	char					param[PARAM_MAX * 4];
	unsigned int			param_size;

	unsigned int			byte_count; // fonction calcul taille -> sizeof(char) * 2 + param_size

	struct s_asm_instruct	*next;
}							t_asm_instruct;

/*
** INSTRUCT
*/

typedef struct				s_instruct
{
	char					name[INSTRUCT_LENGTH_MAX + 1];
	char					*param[PARAM_MAX];
	struct s_instruct		*next;
}							t_instruct;

/*
** LABEL
*/

typedef struct				s_label
{
	char					name[LABEL_LENGTH_MAX];
	t_instruct				*instruc_list;
	t_asm_instruct			*asm_instruct_list;
	struct s_label			*next;
}							t_label;

/*
** ASM
*/

typedef struct				s_asm
{
	t_header				header;
	t_label					*label_list;
}							t_asm;

/*
** CORE
*/

/*
** asm_usage.c
*/
int							asm_usage(void);

/*
** asm_syntax_error.c
*/
int							asm_syntax_error(const char *init_ptr,
								const char *error_ptr, const char *message);

/*
** READDER
*/

typedef struct				s_parser
{
	char					*file_content;
	char					*current_ptr;
}							t_parser;

/*
** get_file_content.c
*/
int							asm_get_file_content(const char *filename,
								char **out_content);

/*
** asm_line_is_comment.c
*/
int							asm_line_is_comment(const char *line);
char						*asm_skip_commented_lines(const char *line);

/*
** asm_get_next_instruct.c
*/
char						*asm_get_next_instruct(const char *file_content);

/*
** asm_get_asm_from_file_content.c
*/
int							asm_get_asm_from_file_content(const char *file,
								t_asm *asm_content);

/*
** STRUCTS
*/

/*
** header
*/

typedef int					(*t_ft_parse_header)(t_parser *, t_header *);

int							asm_t_header_init_from_file(t_parser *parser,
								t_header *out_header);


int							asm_t_header_get_name(t_parser *parser,
								t_header *header);
int							asm_t_header_get_comment(t_parser *parser,
								t_header *header);

/* temp */

t_label						*asm_t_label_new(void);
int							asm_t_label_init();
void						asm_t_label_del(t_label **label);

t_instruct					*asm_t_instruct_new(void);
int							asm_t_instruct_init();
void						asm_t_instruct_del(t_instruct **instruct);

t_asm_instruct				*asm_t_asm_instruct_new(void);
int							asm_t_asm_instruct_init();
void						asm_t_asm_instruct_del(t_asm_instruct **asm_inst);

#endif
