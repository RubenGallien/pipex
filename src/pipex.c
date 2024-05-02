#include "pipex.h"

int main(int ac, char *argv[])
{
	int	i;
	int	fd;

	i = 0;
	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (ac > 0)
	{
		printf("nb arg : %d\n", ac);
		while (i < ac)
		{
			printf("%s\n",argv[i]);
			i++;
		}
	}

	return (0);
}