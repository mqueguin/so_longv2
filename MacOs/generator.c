#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < atoi(av[1]))
	{
		putchar('1');
		i++;
	}
	putchar('\n');
	i = 0;
	while (i < atoi(av[2]))
	{
		putchar('1');
		j = 0;
		while (j < atoi(av[1]) - 2)
		{
			if (i == 14 && j == 27)
				putchar('C');
			else if (i == 15 && j == 26)
				putchar('P');
			else if (i == 16 && j == 26)
				putchar('E');
			else
				putchar('0');
			j++;
		}
		putchar('1');
		putchar('\n');
		i++;
	}
	i = 0;
	while (i < atoi(av[1]))
	{
		putchar('1');
		i++;
	}
	return (0);
}