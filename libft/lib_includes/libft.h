/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:31:48 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/04 14:52:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>

/*/////////////////////////////////////////////////////////////////////////////
		DEFINES
*//////////////////////////////////////////////////////////////////////////////

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# define UPPERHEX "0123456789ABCDEF"
# define LOWERHEX "0123456789abcdef"
# define BASEDEC "0123456789"
# define PRINTFCSET "scdiuxXp"

/*/////////////////////////////////////////////////////////////////////////////
		BOOLEAN FUNCTIONS
*//////////////////////////////////////////////////////////////////////////////

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

int		ft_ischarset(char c, char *set);
int		ft_isnotcharset(char c, char *set);

/*/////////////////////////////////////////////////////////////////////////////
		MEMORY MANAGEMENT FUNCTIONS
*//////////////////////////////////////////////////////////////////////////////

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

void	ft_free(char **str);

/*/////////////////////////////////////////////////////////////////////////////
		STR MANAGEMENT FUNCTIONS
*//////////////////////////////////////////////////////////////////////////////

int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_itoa(int n);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);

char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnjoin(const char *s1, const char *s2, ssize_t index);
int		ft_int_strchr(const char *s, int c);
long	ft_atol(const char *str);

/*/////////////////////////////////////////////////////////////////////////////
		PRINT FUNCTIONS
*//////////////////////////////////////////////////////////////////////////////

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		ft_int_putchar(int c);
int		ft_int_putstr(char *s);
int		ft_int_putptr(unsigned long long nbr);
int		ft_int_putnbr(int n);
int		ft_int_putnbr_base(unsigned int nbr, char *base);

/*/////////////////////////////////////////////////////////////////////////////
		LINKED LISTS
*//////////////////////////////////////////////////////////////////////////////

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_front(t_list **alst, t_list *newlst);
void	ft_lstadd_back(t_list **alst, t_list *newlst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*/////////////////////////////////////////////////////////////////////////////
		PROJECTS FUNCTIONS
*//////////////////////////////////////////////////////////////////////////////

char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);

#endif