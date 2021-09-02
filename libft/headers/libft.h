/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:55:07 by alisa             #+#    #+#             */
/*   Updated: 2021/09/02 01:08:03 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_gnl_list
{
	int					fd;
	char				*buffer_start;
	char				*buffer;
	struct s_gnl_list	*next;
}	t_gnl_list;

void				ft_swap(int *a, int *b);
int					ft_strncmp(char *s1, char *s2, size_t n);
size_t				ft_strlen(const char *str);
int					ft_strcmp(char *s1, char *s2);
void				ft_putstr(char *str);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
char				*ft_strnstr(const char *big, const char *small, size_t n);
char				*ft_strchr(const char *str, int chr);
char				*ft_strrchr(const char *str, int chr);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_bzero(void *str, size_t n);
void				*ft_memset(void *str, int val, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int chr, size_t n);
void				*ft_memchr(const void *str, int chr, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
int					ft_isalpha(int chr);
int					ft_isdigit(int chr);
int					ft_isalnum(int chr);
int					ft_isascii(int chr);
int					ft_isprint(int chr);
int					ft_toupper(int chr);
int					ft_tolower(int chr);
long int			ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_printclst(t_list *lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
						void *(*f)(void *), void (*del)(void *));
int					get_next_line(int fd, char **line);
t_gnl_list			*gnl_lstnew(int fd);
t_gnl_list			*gnl_lstfind(int fd, t_gnl_list *start);
void				gnl_lstdel(t_gnl_list **start, int fd);
int					check_n(int n, char **line);

#endif
