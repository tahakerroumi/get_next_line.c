#include "get_next_line.h"

int	main(void)
{
	int		i;
	char	*s;
	int		p;

	i = open("text.txt", O_RDONLY);
	s = get_next_line(i);
	// printf("%s" , s);
	// free(s);
	p = 0;
	while (p < 5)
	{
		printf("%s", s);
		free(s);
		p++;
		s = get_next_line(i);
	}
}