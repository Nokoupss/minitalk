/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:01:00 by nbelkace          #+#    #+#             */
/*   Updated: 2024/02/02 14:26:06 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdarg.h>

/*
**	Libft
*/

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*
**	ft_printf
*/

int		ft_putstr(char *str);
int		ft_putchar(char c);
int		nbrcase(long int nbr, char *base);
int		nbrcase_address(unsigned long int nbr, char *base);
char	*ft_itoa_base(long int nbr, char *base);
char	*ft_itoa_base_address(unsigned long int nbr, char *base);
int		ft_printnbr_d(int n);
int		ft_printnbr_i(int n);
int		ft_printnbr_u(unsigned int n);
int		ft_printnbr_x(unsigned int n);
int		ft_printnbr_uppercase_x(unsigned int n);
int		ft_printaddress_p(unsigned long int p);
int		ft_printf(const char *str, ...);
int		is_type(char c, va_list args);

/*
**	get_next_line
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		is_charset_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*readfile(int fd, char *stash);
char	*copy_stash(char *stash);
char	*vide_stash(char *stash);
char	*get_next_line(int fd);

#endif
