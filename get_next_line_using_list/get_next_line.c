#include "get_next_line.h"

void	create_list(t_list **list, int fd)
{
	char	*buf;
	ssize_t	bytes_read;
	// size_t	i;

	while (check_newline(*list) != 1)
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
		{
			ft_lstclear(list, del_content);
			return ;
		}
		// ft_bzero(buf, (BUFFER_SIZE + 1) * sizeof(char));
		// i = 0;
		// while (i < ((BUFFER_SIZE + 1) * sizeof(char)))
		//   ((unsigned char *)buf)[i++] = 0;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buf);
			if (bytes_read < 0)
				ft_lstclear(list, del_content);
			return ;
		}
		buf[bytes_read] = '\0';
		create_new_node(list, buf);
	}
}

char	*get_line(t_list *list)
{
	int	str_len;
	char	*new_line;

	if (list == NULL)
		return (NULL);
	str_len = newline_len(list);
	new_line = malloc(str_len + 1);
	if (new_line == NULL)
		return (NULL);
	copy_str(list, new_line);
	return (new_line);
}

// void clean_list(t_list **list)
// {
//   t_list  *last_node;
//   char  *remaining_content;

//   if (*list == NULL)
//     return;
//   last_node = ft_lstlast(*list);
//   int i = 0;
//   while (last_node->content[i] && last_node->content[i] != '\n')
//     i++;
//   if (last_node->content[i] == '\n')
//     i++;
//   remaining_content = ft_strdup(&last_node->content[i]);
//   if (remaining_content == NULL)
//     return;

//   ft_lstclear(list, del_content);
//   *list = ft_lstnew(remaining_content);
// }

void	clean_list(t_list **list)
{
	t_list	*node = *list;
	char	*remaining_content = NULL;
	int	i = 0;

	while (node)
	{
			while (node->content[i] && node->content[i] != '\n')
					i++;
			if (node->content[i] == '\n')
			{
					i++;
					remaining_content = ft_strdup(&node->content[i]);
					if (!remaining_content)
					{
							ft_lstclear(list, del_content);
							return;
					}
					break;
			}
			node = node->next;
	}
	ft_lstclear(list, del_content);
	if (remaining_content)
		*list = ft_lstnew(remaining_content);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char	*next_line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);

	create_list(&list, fd);
	if (list == NULL)
		return (NULL);

	next_line = get_line(list);
	if (!next_line)
	{
		ft_lstclear(&list, del_content);
		return (NULL);
	}

	clean_list(&list);
	return (next_line);
}
