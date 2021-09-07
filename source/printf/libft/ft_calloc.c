#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(size * count);
	if (p != NULL)
	{
		while (i != size * count)
		{
			p[i] = 0;
			i++;
		}
		return ((void *)p);
	}
	return (NULL);
}
