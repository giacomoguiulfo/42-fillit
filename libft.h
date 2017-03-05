/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:58:53 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 21:11:15 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

# define CHK(a, b) do{if(a){return(b);}}while(0)
# define CHK1(a, b, c) do{if(a){b; return(c);}}while(0)
# define ISSPACE(a) ((a >= 9 && a <= 13) || (a == 32))
# define ISDIGIT(a) (a >= 48 && a <= 57)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *src, size_t sze);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void(*f)(t_list *cnt));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *cnt));
void				ft_lstdel(t_list**alst, void(*del)(void*, size_t));

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putstr(char const *src);
void				ft_putstr_fd(char const *src, int fd);
void				ft_putendl(char const *src);
void				ft_putendl_fd(char const *src, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_strcmp(const char *src1, const char *src2);
int					ft_strncmp(const char *src1, const char *src2, size_t len);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *src1, const char *src2, size_t len);
size_t				ft_strlcat(char *src1, const char *src2, size_t size);
size_t				ft_strlen(const char *src);
size_t				ft_strnlen(const char *src, size_t maxlen);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strdup(const char *src);
char				*ft_strndup(const char *src, size_t len);
char				*ft_strstr(const char *src, const char *to_find);
char				*ft_strnstr(const char *src, const char *to_find, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *src);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				**ft_strsplit(const char *src, char c);
char				**strsplit(const char *src, char src_x);

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t len);
char				*ft_strmap(char const *src, char (*f)(char));
char				*ft_strmapi(char const *src, char (*f)(unsigned int, char));
char				*ft_strsub(char const *src, unsigned int start, size_t len);
char				*ft_strjoin(char const *src1, char const *src2);
char				*ft_strtrim(char const *src);

int					ft_isalnum(int c);
int					ft_isalpha(int	c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isdigit(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_ispunct(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *s, int s_c, size_t len);
void				*ft_memchr(const void *src, int src_c, size_t len);
int					ft_memcmp(const void *src1, const void *src2, size_t len);
void				ft_bzero(void *src, size_t len);
void				*ft_memset(void *src, int c, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

int					ft_atoi(const char *str);
char				*ft_itoa(int nb);
int					ft_abs(int i);
#endif
