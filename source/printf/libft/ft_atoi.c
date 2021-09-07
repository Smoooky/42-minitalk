#include "libft.h"

static int	ft_sub_atoi(const char *str, int i, int sign);

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = sign * -1;
	}
	res = ft_sub_atoi(str, i, sign);
	return (res * sign);
}

static int	ft_sub_atoi(const char *str, int i, int sign)
{
	int	dig;
	int	tens;
	int	res;

	res = 0;
	dig = 0;
	tens = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		dig++;
		i++;
	}
	if ((dig > 10) && (sign == 1))
		return (-1);
	if ((dig > 10) && (sign == -1))
		return (0);
	i--;
	while (dig != 0)
	{
		res = res + (str[i] - 48) * tens;
		tens = tens * 10;
		dig--;
		i--;
	}
	return (res);
}
