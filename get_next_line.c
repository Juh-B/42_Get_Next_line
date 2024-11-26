#include "get_next_line.h"

static char *get_line(char *stored, char *buf)
{
  char  *temp;

  if (stored == NULL)
    stored = ft_strjoin("", buf);
  else
  {
    temp = stored;
    stored = ft_strjoin(stored, buf);
    free(temp);
  }
  return (stored);
}

static char  *read_and_stored(int fd, char *stored)
{
  char  *buf;
  ssize_t   bytes_read;

  buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
  ft_bzero(buf, (BUFFER_SIZE + 1) * sizeof(char));
  if (buf == NULL)
    return(NULL);

  bytes_read = 1;
  while (bytes_read > 0 && (ft_strchr(buf, '\n') == NULL || stored == NULL))
  {
    bytes_read = read(fd, buf, BUFFER_SIZE);
    if (bytes_read < 0)
    {
      free(buf);
      return (NULL);
    }
    buf[bytes_read] = '\0';
    stored = get_line(stored, buf);
  }
  free(buf);
  return (stored);
}

static size_t  line_size(char *str)
{
  size_t    line_len;

  line_len = 0;
  while (str[line_len] && str[line_len] != '\n')
      line_len++;
  if (str[line_len] == '\n')
      line_len++;
  return (line_len);
}

char	*get_next_line(int fd)
{
  static char *stored;
  char  *line;
  char  *temp;
  size_t    line_len;

  if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
  stored = read_and_stored(fd, stored);
  if (stored == NULL || *stored == '\0')
{
    free(stored);
    stored = NULL;
    return (NULL);
}
  line_len = line_size(stored);
  line = ft_substr(stored, 0, line_len);
  temp = stored;
  stored = ft_substr(stored, line_len, ft_strlen(stored) - line_len);
  free(temp);
  return (line);
}

// MAIN
// int	main(int argc, char **argv)
// {
// 	int	file_descriptor;
// 	char	*line;
//   int n;

//   n = 1;
// 	if (argc < 2)
// 	{
// 		write(1, "File name missing.\n", 19);
// 		return (1);
// 	}
// 	if (argc > 2)
// 	{
// 		write(1, "Too many arguments.\n", 20);
// 		return (1);
// 	}
// 	file_descriptor = open(argv[1], O_RDONLY);
// 	if (file_descriptor == -1)
// 	{
// 		write(1, "Error opening file!\n", 20);
// 		return (1);
// 	}
// 	while ((line = get_next_line(file_descriptor)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(file_descriptor);
// 	return (0);
// }
