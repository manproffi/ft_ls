#include "head_ls.h"

void	resursion(t_info *info, t_list **mass, int size, char *name)
{
	int		i;
	int		flag;
	t_list 	*list;
	char	*new_name;

	i = -1;
	list = NULL;
	while (++i < size)
	{
		// if (check if this folder)
		{
			new_name = ft_strjoin(name, /*folder_name*/);
			printf("%s:\n", new_name);
			list = reading(info, mass[i]->content, &flag);
			next_stage(list, info, new_name);
		}
	}
}