#include "libft.h"

void	ft_getsubstr(char *s, unsigned int start, size_t len)
{
	size_t		j;
	size_t		length;

	if (!s)
		return ;
	j = 0;
	length = ft_strlen(s);
	if (start >= length)
	{
		ft_getmemset(s, '\0', length);
		return ;
	}
	while (j < len)
	{
		s[j] = s[j + start];
		j++;
	}
	s[j] = '\0';
}
