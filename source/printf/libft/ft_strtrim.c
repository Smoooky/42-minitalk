#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	beg;
	size_t	count;
	char	*res;

	count = 0;
	beg = 0;
	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	while (s1[beg] != '\0' && ft_strchr(set, s1[beg]))
		beg++;
	while (beg < len_s1 && ft_strchr(set, s1[len_s1 - 1]))
		len_s1--;
	res = (char *) malloc(sizeof(char) * (len_s1 - beg + 1));
	if (res == NULL)
		return (NULL);
	while (beg < len_s1)
	{
		res[count] = s1[beg];
		beg++;
		count++;
	}
	res[count] = '\0';
	return (res);
}
