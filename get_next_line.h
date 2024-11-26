#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Lib for malloc, size_t and read
# include <stdlib.h>
# include <unistd.h>

// Lib for Open
// #include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

// Utils functions
size_t	ft_strlen(const char *s);
char	  *ft_strdup(const char *s);
char  	*ft_strchr(const char *s, int c);
char	  *ft_strjoin(char const *s1, char const *s2);
char	  *ft_substr(char const *s, unsigned int start, size_t len);
void  	ft_bzero(void *s, size_t n);

#endif
