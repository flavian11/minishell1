/*
** my_setenv.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Tue Jan 10 14:59:28 2017 Flavian Feugueur
** Last update Sun Jan 22 15:17:10 2017 Flavian Feugueur
*/

#include "minishell.h"

static char	**new_envp(char **envp, char *str, char *path_env)
{
  int	x;
  int	y;
  int	i;
  char	**tmp;

  y = i = 0;
  x = my_tablen(envp);
  tmp = malloc(sizeof(char *) * my_tablen(envp) + 1);
  tmp = envp;
  if ((tmp[x] = malloc(sizeof(char) * my_strlen(str) +
		       my_strlen(path_env) + 1)) == NULL)
    exit(84);
  while (path_env[i] != '\0')
    tmp[x][y++] = path_env[i++];
  tmp[x][y++] = '=';
  i = 0;
  while (str[i] != '\0')
    tmp[x][y++] = str[i++];
  tmp[x][y] = '\0';
  tmp[x + 1] = NULL;
  return (tmp);
}

static void	wich_path(char *path_env, char *cmd)
{
  int	i_cmd;
  int	i_path;

  i_path = 0;
  i_cmd = 7;
  while (cmd[i_cmd] != '\0' && cmd[i_cmd] != '\n' && cmd[i_cmd] != ' ')
    {
      path_env[i_path] = cmd[i_cmd];
      i_path++;
      i_cmd++;
    }
  path_env[i_path] = '\0';
}

static int	find_envp(char **envp, char *path_env)
{
  int	i;
  int	n;

  i = n = 0;
  while (envp[i][n] != '=')
    n++;
  while (my_strncmp(path_env, envp[i], n) != 0 && envp[i] != NULL)
    {
      i++;
      if (envp[i] == NULL)
	return (-1);
      n = 0;
      while (envp[i][n] != '=')
	n++;
    }
  return (i);
}

static void	init_str(char *str, char *cmd)
{
  int	i;
  int	space;
  int	i_str;

  i = space = i_str = 0;
  while (space < 2 && cmd[i] != '\0')
    {
      if (cmd[i] == ' ')
	space++;
      i++;
    }
  while (cmd[i] != '\0' && cmd[i] != '\n')
    str[i_str++] = cmd[i++];
  str[i_str] = '\0';
}

void	my_setenv(char *cmd, char **envp)
{
  int	x;
  char	*path_env;
  char	*str;
  int	check;

  check = 0;
  path_env = malloc(sizeof(char) * my_strlen(cmd));
  str = malloc(sizeof(char) * my_strlen(cmd));
  check = check_setenv(cmd);
  if (check == 0)
    print_env(envp);
  else
    {
      wich_path(path_env, cmd);
      init_str(str, cmd);
      x = find_envp(envp, path_env);
      if (path_env[0] == '\0')
	print_env(envp);
      else if (x != -1)
	old_set_env(envp, str, cmd, path_env);
      else
	envp = new_envp(envp, str, path_env);
    }
}
