#include "server.h"

int	main(int argc, char **argv)
{
	struct sigaction sa;
	char **res;

	if (argc != 1)
		ft_putstr_fd("Error arguments\n", 1);
	write(1, "Server started!\nPID: ", 21);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		write(1, "Wrong signal\n", 13);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(1, "Wrong signal\n", 13);
	while (1)
		pause();
	return (0);
}

void	handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int ascii = 0;
	static int power = 0;
	static t_node	*tab;

//	tab = (t_print *)malloc(sizeof(t_print));
	if
	(void)unused;
	if(signum == SIGUSR1)
		ascii += 1 << (7 - power);
	power += 1;
	if (power == 8)
	{
		if (ascii == 255)
		{
			if (kill(siginfo->si_pid, SIGUSR1) == -1)
				ft_putstr_fd("Error signal\n", 1);
			power = 0;
			ascii = 0;
			return;
		}
		ft_putchar_fd(ascii, 1);
		power = 0;
		ascii = 0;
	}
	if (kill(siginfo->si_pid, SIGUSR2) == -1)
		ft_putstr_fd("Error signal\n", 1);
}

void	print_pid(void)
{
	pid_t pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
}
