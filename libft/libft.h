/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:13:50 by lmoran            #+#    #+#             */
/*   Updated: 2024/02/27 16:57:37 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	long			content;
	int				index;
	int				cost_a;
	int				cost_b;
	int				group;
	struct s_list	*next;
}					t_list;

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isvals(char *s, char *c);
int					ft_iterate(char *s, int (*f)(char *, int));
int					ft_iterate_double(char **s, int (*f)(char **, int, int));
int					ft_make_rand(int i, int j);
int					ft_prchar(int c);
int					ft_prhex(unsigned int n, const char type);
int					ft_printf(const char *s, ...);
int					ft_prnbr(int n);
int					ft_prptr(unsigned long n);
int					ft_prstr(char *s);
int					ft_prtype(unsigned long n);
int					ft_pruns(unsigned int n);
int					ft_ttype(va_list args, const char type);
int					ft_lines_double(char **s);
int					ft_lstsize(t_list *lst);
int					ft_memcmp(const void *s1, const void *s2, size_t size);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t size);
int					ft_strlen(const char *c);
int					ft_strlen_comp(char **s);
int					ft_linelen(char **s);

int					ft_tolower(int c);
int					ft_toupper(int c);

long				ft_atoi(const char *s);

size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcpy_gnl(char *dst, const char *src, size_t size);

char				*ft_itoa(int n);
char				*ft_strdup(const char *s);
char				*ft_strdup_gnl(char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strjoin_gnl(char *s1, char *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *b, const char *s, size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*get_next_line(int fd);

char				**ft_split(char *s, char c, int free_or_not);
char				**ft_strdup_double(char **s);

void				ft_bzero(void *s, size_t size);
void				ft_clean(char *fd_l, char (*s)[BUFFER_SIZE + 1]);
void				ft_free(char **s);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(long));
void				ft_lstdelone(t_list *lst, void (*del)(long));
void				ft_lstiter(t_list *lst, long (*f)(long));
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char *s);
void				ft_putstr_double(char **s);
void				ft_putstr_fd(char *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memchr(const void *s, int c, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t size);
void				*ft_memset(void *s, int c, size_t size);

t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(long content);

#endif
