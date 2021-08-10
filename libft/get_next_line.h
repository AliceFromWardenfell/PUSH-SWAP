/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:42:22 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:58:37 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_gnl
{
	int				fd;
	char			*beyond;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int fd, char **line);
t_gnl				*new_el(int fd, char **line);
int					core(int fd, char **line, char **beyond);
char				*beyond_var(char **line, char **beyond, char **malloc_flag);
char				*ft_strdup(const char *str);
char				*ft_strjoin_m(const char *s1, const char *s2,
						int len1, int len2);
void				ft_strcpy(char *dest, char *src);
char				*ft_strchr(const char *str, int chr);
char				*malloc_ret(char **beyond, char **malloc_flag);
int					ft_strcpy_strlen(char *dest, char *src,
						char *str, char *flag);
int					ft_useless(char **endl_ptr, char *buf,
						char **beyond, char **line);
int					alloc_buf(char **buf);

#endif
