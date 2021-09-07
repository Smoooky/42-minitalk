#include "libft.h"

static int	sub_ft_putunbt_fd(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	char	ch;
	int		div;

	div = 1000000000;
	if (sub_ft_putunbt_fd(n, fd) == 1)
		return ;
	else if (n < 0)
	{
		ch = '-';
		write(fd, &ch, 1);
		n = -1 * n;
	}
	while (n / div == 0)
		div = div / 10;
	while (div != 0)
	{
		ch = '0' + n / div;
		write(fd, &ch, 1);
		n = n % div;
		div = div / 10;
	}
}

static int	sub_ft_putunbt_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	return (0);
}
