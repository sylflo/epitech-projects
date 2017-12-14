/*
** my_script.h for  in /home/chatea_s/project/unix/my_script
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Jan 30 20:04:49 2014 Sylvain Chateau
** Last update Sun Mar  2 21:47:33 2014 Sylvain Chateau
*/

#ifndef MY_SCRIPT_H_
# define MY_SCRIPT_H_

#include <pty.h>
#include <fcntl.h>
#include <utmp.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int			g_pid;
typedef struct termios	t;
typedef struct winsize	w;

typedef struct		s_script
{
  int			append;
  char			*file;
  int			fd_slave;
  int			fd_master;
  int			fd_file;
  char			*name_slave;
  pid_t			pid;
}			t_script;

int			getpt(void);
pid_t			my_forkpty(t_script *, const t *, const  w *);
int			my_unlockpt (int);
int			open_tty(int *, int *, const t *,  const w *);
int			my_login_tty(int);
int			my_dup2(int, int);
int			mode_no_canon(int);
int			mode_canon(int);
void			child(int);
void			my_write(int, char *);
char			*get_time();
void			parse_arg(int, char **, t_script *);
int			exec(t_script *script);

#endif /* MY_SCRIPT_H_ */
