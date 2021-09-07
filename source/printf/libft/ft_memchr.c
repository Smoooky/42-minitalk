#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		ch;
	const unsigned char	*p;

	ch = c;
	p = s;
	while ((n != 0) && (*(unsigned char *)p != ch))
	{
		n--;
		p++;
	}
	if (n != 0)
		return ((void *)(p));
	else
		return (NULL);
}
