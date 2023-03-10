

#include "libft.h"

int	ft_len_unsigned(unsigned int nb)
{
	int		len;

	len = 0;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_utoa(unsigned int nb)
{
	int		len;
	char	*result;

	len = ft_len_unsigned(nb);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (nb != 0)
	{
		result[len - 1] = nb % 10 + 48;
		nb /= 10;
		len--;
	}
	return (result);
}

int	ft_print_unsigned(unsigned int nb)
{
	int		len;
	char	*n;

	len = 0;
	if (nb == 0)
		len += write(1, "0", 1);
	else
	{
		n = ft_utoa(nb);
		len += ft_printstr(n);
		free(n);
	}
	return (len);
}
