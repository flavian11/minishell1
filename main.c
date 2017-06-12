/*
** main.c for  in /home/flavian.feugueur/PSU/PSU_2016_minishell1
**
** Made by Flavian Feugueur
** Login   <flavian.feugueur@epitech.net>
**
** Started on  Mon Jan  2 20:14:31 2017 Flavian Feugueur
** Last update Sun Jan 22 21:45:11 2017 Flavian Feugueur
*/

#include "minishell.h"

void	father2(int status)
{
  if (status == 139)
    my_putstr("Segmentation fault (core dumped)\n");
  else if (status == 134)
    my_putstr("Abort (core dumped)\n");
  else if (status == 1)
    my_putstr("Hangup\n");
  else if (status == 2)
    my_putstr("\n");
  else if (status == 131)
    my_putstr("Quit (core dumped)\n");
  else if (status == 132)
    my_putstr("Illegal instruction (core dumped)\n");
  else if (status == 133)
    my_putstr("Trace/BPT trap (core dumped)\n");
  else if (status == 135)
    my_putstr("Bus error (core dumped)\n");
  else if (status == 136)
    my_putstr("Floating exception (core dumped)\n");
  else if (status == 9)
    my_putstr("Killed\n");
  else if (status == 10)
    my_putstr("User signal 1\n");
  else if (status == 12)
    my_putstr("User signal 2\n");
}

void	father(int pid)
{
  int	status;

  wait(&status);
  father2(status);
  if (status == 13)
    my_putstr("Broken pipe\n");
  if (status == 14)
    my_putstr("Alarm clock\n");
  if (status == 15)
    my_putstr("Terminated\n");
  if (status == 16)
    my_putstr("Stack limit exceeded\n");
  if (status != 0)
    kill(pid, status);
}

int	sh(char *cmd, char **envp)
{
  char	**str;
  pid_t	pid;

  str = my_str_to_word_tab(cmd);
  if (my_strcmp(str[0], "exit") == 0)
    return (32);
  else if (my_strcmp(str[0], "cd") == 0)
    my_cd(cmd, envp);
  else if (my_strcmp(str[0], "env") == 0)
    print_env(envp);
  else if (my_strncmp(cmd, "setenv ", 7) == 0)
    my_setenv(cmd, envp);
  else if (my_strcmp(cmd, "setenv") == 0)
    print_env(envp);
  else if ((pid = fork()) == -1)
    return (84);
  else if (pid == 0)
    {
      my_exec(cmd, str, envp);
      return (11);
    }
  else if (pid != 0)
    father(pid);
  return (0);
}

int	sh_loop(char **envp)
{
  int	ret;
  int	i_sh;
  char *cmd;

  i_sh = ret = 0;
  while (42)
    {
      if (isatty(0) == 1)
	my_putstr("lolilolsh$>");
      if ((cmd = get_next_line(0)) == NULL)
	{
	  if (isatty(0) == 1)
	    my_putstr(" exit\n");
	  break;
	}
      replace_tab(cmd);
      if (cmd[0] != '\0')
	i_sh = sh(cmd, envp);
      if (i_sh == 32)
	ret = my_exit(my_str_to_word_tab(cmd));
      if (i_sh == 11 || i_sh == 32)
	break;
    }
  return (ret);
}

int	main(int ac, char **av, char **envp)
{
  int	ret;
  char	**my_envp;

  (void)ac;
  (void)av;
  if (!envp)
    return (0);
  signal(SIGINT, ctrlc);
  my_envp = malloc(sizeof(char *) * my_tablen(envp) + 1);
  my_envp = my_tabcp(envp);
  ret = sh_loop(my_envp);
  return (ret);
}
