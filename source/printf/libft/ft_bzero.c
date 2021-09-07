#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ch;

	ch = s;
	while (n != 0)
	{
		*ch = 0;
		ch++;
		n--;
	}
	return (ch);
}
