/*
** my_cd.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Tue Jan  3 16:23:50 2017 Flavian Feugueur
** Last update Sun Jan 22 15:13:36 2017 Flavian Feugueur
*/

#include "minishell.h"

static int	my_strlen_custom(char *s, int i)
{
  while (s[i] != '\0')
    i++;
  return (i);
}

char	*my_home(char **envp)
{
  int	i;
  char	*path;
  int	y;
  int	i_path;

  i = i_path = 0;
  y = 5;
  while (my_strncmp(envp[i], "HOME=", 5) != 0 && envp[i] != NULL)
    i++;
  path = malloc(sizeof(char) * my_strlen_custom(envp[i], 5) + 1);
  while (envp[i][y] != '\0')
    {
      path[i_path] = envp[i][y];
      i_path++;
      y++;
    }
  path[i_path] = '\0';
  return (path);
}

static char	*pars_my_path(char *cmd, char **envp)
{
  char	*path;
  int	i;
  int	i_path;

  i = 3;
  i_path = 0;
  path = malloc(sizeof(char) * my_strlen_custom(cmd, 3) + 1);
  path[my_strlen_custom(cmd, 3)] = '\0';
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '\n')
	path[i_path] = '\0';
      else
	path[i_path] = cmd[i];
      i_path++;
      i++;
    }
  path[i_path] = '\0';
  if (my_strncmp(path, "~", 1) == 0)
    path = my_home(envp);
  return (path);
}

static void	change_pwd(char **envp)
{
  char	*tmp;
  char	*pwd;
  t_change_pwd	change_pwd;

  change_pwd.x = change_pwd.i_tmp = change_pwd.y = 0;
  if ((pwd = malloc(sizeof(char) * 1000)) == NULL)
    exit(84);
  if (getcwd(pwd, 1000) == NULL)
    exit(84);
  while (my_strncmp(envp[change_pwd.x], "PWD", 3) != 0
	 && envp[change_pwd.x] != NULL)
    change_pwd.x++;
  if ((tmp = malloc(sizeof(char) * my_strlen(envp[change_pwd.x]))) == NULL)
    exit(84);
  tmp = envp[change_pwd.x];
  if ((envp[change_pwd.x] = malloc(sizeof(char) * my_strlen(pwd) + 5)) == NULL)
    exit(84);
  while (tmp[change_pwd.i_tmp] != '=' && tmp[change_pwd.i_tmp] != '\0')
    envp[change_pwd.x][change_pwd.y++] = tmp[change_pwd.i_tmp++];
  envp[change_pwd.x][change_pwd.y++] = '=';
  change_pwd.i_tmp = 0;
  while (pwd[change_pwd.i_tmp] != '\0')
    envp[change_pwd.x][change_pwd.y++] = pwd[change_pwd.i_tmp++];
  envp[change_pwd.x][change_pwd.y] = '\0';
  free(pwd);
}

void	my_cd(char *cmd, char **envp)
{
  char	*path;
  static char	oldpwd[1000];
  int	a;

  a = 0;
  path = pars_my_path(cmd, envp);
  if (path[0] == '\0')
    path = my_home(envp);
  if (path[0] == '-')
    {
      chdir(oldpwd);
      a = 1;
    }
  if (getcwd(oldpwd, 1000) == NULL)
    exit(84);
  if (a != 1)
    if (chdir(path) == -1)
      {
	my_putstr(path);
	my_putstr(": No such file or directory.\n");
      }
  change_pwd(envp);
}
