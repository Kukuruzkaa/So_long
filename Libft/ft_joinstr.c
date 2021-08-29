#include "libft.h"

char	*ft_joinstr(char *s1, char *s2, size_t size)
{
	size_t	str1len;
	size_t	i;
	size_t	j;
	char	*s3;

	str1len = ft_strlen(s1);
	if (!(s3 = (char*)malloc(sizeof(char) * (str1len + size + 1))))
		return (NULL);
	i = 0;
	while (i < str1len)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < size)
	{
		s3[str1len + j] = s2[j];
		j++;
	}
	s3[str1len + size] = '\0';
	free(s1);
	s1 = NULL;
	return (s3);
}