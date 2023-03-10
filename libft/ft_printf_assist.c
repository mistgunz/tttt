

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(const char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static size_t	ft_get_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t		len;
	long int	nb;
	char		*result;

	len = ft_get_len(n);
	nb = n;
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	if (n == 0)
		result[0] = '0';
	result[len--] = '\0';
	while (nb)
	{
		result[len] = nb % 10 + '0';
		nb /= 10;
		len --;
	}
	return (result);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*nb;

	nb = ft_itoa(n);
	len = ft_printstr(nb);
	free(nb);
	return (len);
}
