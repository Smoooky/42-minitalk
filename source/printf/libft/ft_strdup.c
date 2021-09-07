#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p != NULL)
	{
		while (i != len)
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = s1[i];
		return (p);
	}
	return (NULL);
}
