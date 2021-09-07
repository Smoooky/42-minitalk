#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned long	i;
	unsigned char	ch;

	ch = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		if (((unsigned char *)src)[i - 1] == ch)
			return (&((unsigned char *)dst)[i]);
	}
	return (NULL);
}
