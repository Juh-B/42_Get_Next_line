#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Lib for malloc, size_t and read
# include <stdlib.h>
# include <unistd.h>

// Lib for Open
// #include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

// USING LIST
typedef struct s_list
{
  char          *content;
  struct s_list *next;
}               t_list;

size_t	ft_strlen(const char *s);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void   	ft_lstadd_back(t_list **lst, t_list *new);
void  	ft_lstdelone(t_list *lst, void (*del)(void *));
void  	ft_lstclear(t_list **lst, void (*del)(void *));
void    del_content(void *content);
void    create_new_node(t_list **list, char *buf);
void    create_list(t_list **list, int fd);
void    copy_str(t_list *list, char *str);
void    clean_list(t_list **list);
char	  *ft_strdup(const char *s);
char    *get_line(t_list *list);
int     check_newline(t_list *list);
int     newline_len(t_list *list);

// USING FUNCTIONS
// Utils functions
// size_t	ft_strlen(const char *s);
// char	  *ft_strdup(const char *s);
// char  	*ft_strchr(const char *s, int c);
// char	  *ft_strjoin(char const *s1, char const *s2);
// char	  *ft_substr(char const *s, unsigned int start, size_t len);
// void  	ft_bzero(void *s, size_t n);

#endif
