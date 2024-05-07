#include "pipex.h"

int	main(int ac, char **av,char **envp)
{
	int	pipeline;
	char **all_path;

	if (!envp)
		return (-1);
	pipeline = ac - 4;
	all_path = ft_split(find_env(envp) + ft_strlen("PATH="), ':');
	int i = 0;
	while (all_path[i])
	{
		ft_printf("%s\n", all_path[i]);
		i++;
	}
	ft_printf("nb_args = %d\n%s\n", pipeline, av[0]);
	return (ft_free_tab(all_path), 0);
}