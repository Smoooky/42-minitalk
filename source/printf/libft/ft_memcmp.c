#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				res;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	res = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i != n)
	{
		if (str1[i] == str2[i])
			res = res + 0;
		else
		{
			res = str1[i] - str2[i];
			return (res);
		}
		i++;
	}
	return (res);
}
//int	ft_memcmp(const void *s1, const void *s2, size_t n)
//{
//	size_t	i;
//	int		res;
//
//	i = 0;
//	res = 0;
//	while (i != n)
//	{
//		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
//			res = res + 0;
//		else
//		{
//			res = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
//			return (res);
//		}
//		i++;
//	}
//	return (res);
//}
