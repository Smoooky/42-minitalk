#include "libft.h"

static int	ft_count_words(char const *s, char c);
static char	*ft_add_word(char const *word_star, int len);
static int	ft_wordlen(char const *s, char c);
static char	**ft_free_res(char **str);

char	**ft_split(char const *s, char c)
{
	int		next;
	int		count;
	char	**res;

	next = 0;
	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (NULL == res)
		return (NULL);
	while (next < count)
	{
		while (*s != '\0' && *s == c)
			s++;
		res[next] = ft_add_word(s, ft_wordlen(s, c));
		if (NULL == res[next])
			return (ft_free_res(res));
		s = s + ft_wordlen(s, c);
		next++;
	}
	res[next] = NULL;
	return (res);
}

static char	*ft_add_word(char const *word_star, int len)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (NULL == res)
		return (NULL);
	while (i != len)
	{
		res[i] = word_star[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		res++;
		i++;
	}
	return (res);
}

static int	ft_count_words(char const *s, char c)
{
	int	is_word;
	int	count;
	int	i;

	i = 0;
	count = 0;
	is_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			is_word = 0;
		if (s[i] != c && is_word == 0)
		{
			count++;
			is_word = 1;
		}
		i++;
	}
	return (count);
}

static char	**ft_free_res(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
