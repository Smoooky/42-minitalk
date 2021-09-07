#include "libft.h"

static unsigned short	ft_countsize(long long t);

char	*ft_itoa(int n)
{
	char			*res;
	long long		t;
	unsigned short	size;

	t = n;
	size = ft_countsize(t);
	res = (char *) malloc(sizeof(char) * (size + 1));
	if (NULL == res)
		return (NULL);
	res[size] = '\0';
	size = size - 1;
	if (t < 0)
	{
		res[0] = '-';
		t = t * -1;
	}
	if (t == 0)
		res[0] = '0';
	while (t > 0)
	{
		res[size] = (t % 10) + '0';
		t = t / 10;
		size--;
	}
	return (res);
}

static unsigned short	ft_countsize(long long n)
{
	unsigned short	res;

	res = 0;
	if (n == 0)
		res++;
	if (n < 0)
	{
		n = n * -1;
		res++;
	}
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}
