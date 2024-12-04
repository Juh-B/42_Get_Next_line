#include "get_next_line.h"

// LIBFT Functions
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p;

	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			p = lst;
		lst = lst->next;
	}
	return (p);
}

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last_p;

// 	if (lst == NULL || new == NULL)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	last_p = ft_lstlast(*lst);
// 	last_p->next = new;
// }

// this one is new
void del_content(void *content)
{
	free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		next_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_node;
	}
	*lst = NULL;
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		str_len;
	char	*dup;

	i = 0;
	str_len = ft_strlen(s);
	dup = (char *)malloc((str_len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// NEW FUNCTIONS

// CREATE NEW NODE without lst functions
// void  create_new_node(t_list **list, char *buf)
// {
//   t_list  *new_node;
// 	t_list	*last_node;

// 	last_node = ft_lstlast(*list);
// 	new_node = malloc(sizeof(t_list));
// 	if (new_node == NULL)
// 		return ;
// 	if (last_node == NULL)
// 		*list = new_node;
// 	else
// 		last_node->next = new_node;
// 	new_node->content = buf;
// 	new_node->next = NULL;
// }

void create_new_node(t_list **list, char *buf)
{
	t_list *new_node;
	t_list *last_node;

	new_node = ft_lstnew(buf);
	if (new_node == NULL)
		return;
	last_node = ft_lstlast(*list);
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
}

// void  create_new_node(t_list **list, char *buf)
// {
//   t_list  *new_node;

//   new_node = ft_lstnew(buf);
//   ft_lstadd_back(list, new_node);
// }

int check_newline(t_list *list)
{
	char  *str;
	while (list)
	{
		str = list->content;
		while (*str)
		{
			if (*str == '\n')
					return (1);
			str++;
		}
		list = list->next;
	}
	return (0);
}

int newline_len(t_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void copy_str(t_list *list, char *str)
{
	int i;
	int j;

	if (list == NULL)
		return ;
	i = 0;
	while (list)
	{
		j = 0;
		while (list->content[j])
		{
			if (list->content[j] == '\n')
			{
				str[i++] = '\n';
				str[i] = '\0';
				return ;
			}
			str[i++] = list->content[j++];
		}
		list = list->next;
	}
	str[i] = '\0';
}
