#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i != n)
	{
		if (s1[i] == s2[i])
			res = res + 0;
		else
		{
			res = (unsigned char) s1[i] - (unsigned char) s2[i];
			return (res);
		}
		i++;
	}
	if (n == i)
		res = (unsigned char) res;
	else
		res = (unsigned char) s1[i] - (unsigned char) s2[i];
	return (res);
}
