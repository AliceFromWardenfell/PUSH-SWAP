#include "get_next_line.h"

int	alloc_buf(char **buf)
{
	buf = malloc((BUFFER_SIZE + 1) * sizeof(*buf));
	if (!buf)
		return (-1);
	return (0);
}
