/*
** minishell.h for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
** 
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
** 
** Started on  Tue Jan  3 14:40:45 2017 Flavian Feugueur
** Last update Sun Jan 22 21:45:57 2017 Flavian Feugueur
*/

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# define READ_SIZE 1024

typedef struct s_change_pwd
{
  int	x;
  int	y;
  int	i_tmp;
}	t_change_pwd;

void	ctrlc();

void	my_putstr(char *s);

int	my_strcmp(char*s1, char *s2);

int	my_strncmp(char *s1, char *s2, int n);

void	print_env(char **envp);

char	**my_str_to_word_tab(char *str);

void	my_cd(char *cmd, char **envp);

int	my_strncmp(char *s1, char *s2, int n);

void	my_cd(char *cmd, char **envp);

void	my_exec(char *cmd, char **str, char **envp);

int	my_strlen(char *s);

void	my_setenv(char *cmd, char **envp);

char	*get_next_line(int fd);

char	**my_ls_option(char **envp, char **str);

int	my_get_nb(char *str);

int	my_tablen(char **str);

int	my_exit(char **str);

void	old_set_env(char **envp, char *str, char *cmd, char *path_env);

int	check_setenv(char *str);

char	*my_strcp(char *s);

char **my_tabcp(char **str);

void	replace_tab(char *str);

#endif /* MINISHELL_H */
