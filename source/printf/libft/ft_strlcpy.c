#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	res;

	res = 0;
	if (!dst || !src)
		return (0);
	while (src[res] != '\0')
		++res;
	if (size == 0)
		return (res);
	i = 0;
	while (src[i] != '\0' && (i + 1) < size)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (res);
}
