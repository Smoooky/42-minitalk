#include "libft.h"

size_t	ft_strlen(const char *s)
{
	register const char	*str;

	str = s;
	while (*s)
		++s;
	return (s - str);
}
