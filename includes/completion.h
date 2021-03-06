/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbopp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:50:30 by lbopp             #+#    #+#             */
/*   Updated: 2017/11/02 12:01:18 by lbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLETION_H
# define COMPLETION_H

# include <dirent.h>
# include <sys/stat.h>

# define COMPLBUFF	130

typedef struct		s_coargs
{
	int				id;
	char			*arg;
	char			*color;
	struct s_coargs	*next;
}					t_coargs;

typedef struct		s_compl
{
	struct s_coargs	*ar;
	size_t			maxlen;
	int				bi;
	int				toskip;
	int				curr;
	int				nbrargs;
	int				isstar;
	int				isdot;
	int				isslash;
	char			*path;
	char			*arg;
	struct s_coargs	args;
}					t_compl;

/*
** completion.c
*/
void				completion(t_cmd *cmd, char ***env, char **buf);
void				compl_addline(t_cmd *cmd, t_compl *compl);

/*
** get_complword.c
*/
char				*get_path(t_cmd *cmd);
void				compl_cmp(t_compl *compl, char **word);

/*
** list_args.c
*/
void				list_compl(t_compl *compl, t_cmd *cmd, char ***env,
					char *path);

/*
** get_binaries.c
*/
void				get_args(t_compl *compl, char **paths);
int					get_files(t_compl *compl, DIR *dirp,
					t_coargs **ar, int *fd);
int					new_complarg(t_coargs **args);
char				*add_backback(char *name);

/*
**	get_locenv.c
*/
void				get_locenv(t_compl *compl);

/*
** display_args.c
*/
void				display_args(t_compl *compl, t_cmd *cmd);
int					*get_size(t_compl *compl, t_cmd *cmd);

/*
** compl_keys.c
*/
int					compl_keys(t_compl *compl, t_cmd *com, char **buf);

/*
** compl_arrow.c
*/
int					compl_arrow(t_compl *compl, t_cmd *cmd, char *buf);

/*
** compl_star.c
*/
int					compl_star(t_compl *compl, t_cmd *cmd);

/*
** compl_color.c
*/
void				compl_addcolor(t_coargs **ar, char *path);

/*
** print_complline.c
*/
void				print_complline(t_compl *compl, t_cmd *cmd,
					int *size, char **buff);
void				add_argtoline(t_compl *compl, t_cmd *cmd);

/*
** compl_buff.c
*/
size_t				print_buff(char **buff);
size_t				buffcat(char **buff, char *s);
size_t				buffncat(char **buff, char *s, size_t n);

/*
** compl_free.c
*/
void				free_tabl(char **tab);
void				compl_free(t_compl *compl);

/*
** add_backchar.c
*/
char				*add_backchar(const char *name);

#endif
