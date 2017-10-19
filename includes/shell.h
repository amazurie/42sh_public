/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:50:54 by hublanc           #+#    #+#             */
/*   Updated: 2017/10/19 13:37:01 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>
# include <signal.h>

# include <termcap.h>
# include <curses.h>
# include <termios.h>
# include <sys/ioctl.h>

# include "exec.h"
# include "lexer.h"
# include "redirection.h"
# include "line_editor.h"
# include "tools.h"
# include "prompt_statement.h"
# include "completion.h"
# include "local.h"

# define CYN	"\x1B[36m"
# define RESET	"\x1B[0m"

typedef struct		s_hist_flags
{
	int				c;
	int				d;
	int				a;
	int				n;
	int				r;
	int				w;
	int				p;
	int				s;
}					t_hist_flags;

/*
**	g_is_child help to know if a child processus is in or not
*/

int					g_is_child;
struct termios		g_term;

/*
**	Built-in
*/
int					ft_echo(char **tab);
int					in_env(char *str, char **env);
int					ft_setenv(char **tab, char ***env);
int					ft_unsetenv(char **tab, char ***env);
int					ft_env(char **env, char **tab);
int					ft_read(char **tab);
char				*read_r_opt(void);
char				*read_without_opt(void);
int					valid_local_var(char **cmd);
int					get_read_opt(char **cmd);
int					put_my_char(int c);
int					read_singleton(int sig);
int					ft_history(char **tab, char ***env, t_control **history);
int					ft_history_2(char **tab, t_control **history, char *file,
					t_hist_flags flags);
int					ft_history_3(char **tab, t_control **history, char *file,
					t_hist_flags flags);
char				*get_history_file(char ***env);
void				get_home(char ***env, char **home);
int					cd(char **path, char ***env);

char				**delonenv(char *name, char **env);
char				**prep_setenv(char *name, char *value);
void				change_pwd(char *path, char ***env, char opt);
char				***save_env(char ***env);

/*
**	terminal
*/
void				set_terminal(void);
void				reset_term(void);
void				reset_disp(void);
int					tputchar(int c);

/*
**	History_builtin
*/

void				init_cd_flags(t_hist_flags *flags);
void				get_cd_flags(t_hist_flags *flags, char **tab,
					int *args_pos);
void				get_cd_flags_2(t_hist_flags *flags, char c);
void				set_usage(char c, int type);
void				print_history(t_control **history);
int					get_num(int size);
void				delete_elem_hist(int index, t_control **history);
void				delete_elem_hist_2(t_lst *tmp, t_control **history);
int					str_isdigit(char *str);
void				print_pflag(char **tab);
int					append_hist_file(t_control **history, char *file_name);
int					rewrite_hist_file(t_control **history, char *file_name);
void				nflag(t_control **history, char *file);
void				print_last_elem(t_control **history, int last);
void				delete_list_content(t_control **history);

#endif
