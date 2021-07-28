#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "printf/includes/ft_printf.h"

void	print_pid(void);
void	handler(int signum, siginfo_t *siginfo, void *unused);
typedef struct	s_node
{
	int 			pid;
	char			*str;
	struct s_node	*next;
}	t_node;

#endif
