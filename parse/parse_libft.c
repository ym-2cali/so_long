#include "../inc/so_long.h"

void	ft_bzero(void *s, int n)
{
	unsigned char	*c;
	int				i;

	c = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
}

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_node	*create_node(char *content)
{
	t_node	*node;

	if (!content)
		return (NULL);
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	fill_list(t_list *list, t_node *node)
{
	if (!list || !node)
		return ;
	if (list->size == 0)
	{
		list->head = node;
		list->tail = node;
		list->size++;
	}
	list->tail->next = node;
	list->tail = node;
	node->next = NULL;
	list->size++;
}