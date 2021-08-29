#include "libft.h"

void	*ft_getmemset(void *b, int c, size_t len)
{
	size_t	index;
	char	*str;

	str = (char*)b;
	index = 0;
	while (index < len)
	{
		str[index] = (unsigned char)c;
		index++;
	}
	return (b);
}