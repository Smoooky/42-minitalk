#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst != NULL || src != NULL)
	{
		if (src > dst)
		{
			i = 0;
			while (i < len)
			{
				((char *) dst)[i] = ((char *) src)[i];
				i++;
			}
		}
		else
		{
			i = len;
			while (i > 0)
			{
				i--;
				((char *) dst)[i] = ((char *) src)[i];
			}
		}
		return (dst);
	}
	return (NULL);
}
