#include "libft.h"
#include <fcntl.h>

char	*re_alloc(void *ptr, int len, int new_len)
{
	char	*new;

	new = malloc(new_len);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, len);
	free(ptr);
	return (new);
}

char	*read_file(int fd, int buf_size, int *out_size)
{
	int		size_read;
	int		total_read;
	char	*buf;
	char	temp_buf[1024];

	buf = malloc(buf_size + 1);
	if (!buf)
		return (NULL);
	total_read = 0;
	while (1)
	{
		size_read = read(fd, temp_buf, sizeof(temp_buf));
		if (size_read <= 0)
			break ;
		buf_size += 1024;
		buf = re_alloc(buf, total_read, buf_size + 1);
		if (!buf)
			break ;
		ft_memcpy(buf + total_read, temp_buf, size_read);
		total_read += size_read;
	}
	buf[total_read] = 0;
	*out_size = total_read;
	return (buf);
}
