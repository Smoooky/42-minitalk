#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;

	if (dst != NULL || src != NULL)
	{
		i = 0;
		while (i < n)
		{
			((char *) dst)[i] = ((char *) src)[i];
			i++;
		}
		return (dst);
	}
	else
		return (NULL);
}
