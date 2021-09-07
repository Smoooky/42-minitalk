#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_a;
	size_t	len_b;
	size_t	len_sum;
	char	*str;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len_a = ft_strlen(s1);
	len_b = ft_strlen((char *)s2);
	len_sum = len_a + len_b + 1;
	str = malloc(sizeof(char) * len_sum);
	if (!str)
		return (0);
	ft_memmove(str, s1, len_a);
	ft_memmove(str + len_a, s2, len_b);
	str[len_sum - 1] = '\0';
	return (str);
}
