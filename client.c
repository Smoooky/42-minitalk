#include "client.h"

void sigerror()
{
	ft_putstr_fd("Error signal!\n", 1);
	exit(0);
}

void	send_eos(int pid)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (kill(pid, SIGUSR1) == -1)
			sigerror();
		i++;
		usleep(100);
	}
}

void	decimal_conversion(char ascii, int power, int pid)
{
	if (power > 0)
		decimal_conversion(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			sigerror();
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			sigerror();
	}
	usleep(100);
}

int	send_message(int server_pid, char *msg)
{
	int		i;

	i = 0;
	while (msg[i] != '\0')
	{
		decimal_conversion(msg[i], 7, server_pid);
		i++;
	}
	send_eos(server_pid);
	return(0);
}

void	notification_handler(int signum, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	if (signum == SIGUSR2)
		ft_putstr_fd("Signal received\n", 1);
	else if (signum == SIGUSR1)
	{
		ft_putstr_fd("Message received\n", 1);
		exit(0);
	}
}

int main(int argc, char **argv)
{
	struct sigaction	sa1;

	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = notification_handler;
	if ((sigaction(SIGUSR2, &sa1, 0)) == -1)
		sigerror();
	if ((sigaction(SIGUSR1, &sa1, 0)) == -1)
		sigerror();
	if (argc == 3)
		send_message(atoi(argv[1]), argv[2]);
	else
	{
		ft_putstr_fd("Error arguments\n", 1);
		return (0);
	}
	while (1)
		pause();
	return (0);
}


