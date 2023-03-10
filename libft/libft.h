/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:21:55 by rnait-el          #+#    #+#             */
/*   Updated: 2023/03/10 03:35:49 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "limits.h"

int		ft_atoi(const char *str);
void	*ft_calloc(size_t nelem, size_t elsize);
int		ft_count_c(char *s, char c);
int		ft_count_lines(int fd, int line_length, int img_w);
int		ft_line_length(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_readfile_and_pushtostash(int fd, char *stash);
char	*get_next_line(int fd);
char	*ft_checkbackn_and_pushtoline(char *stash);
char	*ft_push_cutstash_to_nextstash(char *stash);

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_printstr(const char *str);
int		ft_printptr(unsigned long nb);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_hexa(unsigned int nb, const char format);
char	*ft_itoa(int n);

#endif
