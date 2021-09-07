#include "../../include/server.h"

void	error(int pid, char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("server: unexpected error.\n", 2);
	kill(pid, SIGUSR2);
	exit(1);
}

char	*print_string(char *message)
{
	ft_putstr_fd(message, 1);
	free(message);
	return (NULL);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	c = (char)UCHAR_MAX;
	static int	bits = 0;
	static int	pid = 0;
	static char	*message = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= (SCHAR_MAX + 1) >> bits;
	else if (signum == SIGUSR2)
		c |= (SCHAR_MAX + 1) >> bits;
	if (++bits == 8)
	{
		if (c)
			message = ft_strappc(message, c);
		else
			message = print_string(message);
		bits = 0;
		c = (char)UCHAR_MAX;
	}
	if (kill(pid, SIGUSR1) == -1)
		error(pid, message);
}

int	main(void)
{
	struct sigaction	sa_signal;

	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}
