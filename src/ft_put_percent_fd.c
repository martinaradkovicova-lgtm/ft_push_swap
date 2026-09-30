#include "ft_push_swap.h"

void	ft_put_percent_fd(double disorder, int fd)
{
	int	percent;

	percent = (int)(disorder * 10000);
	ft_putnbr_fd(percent / 100, fd);
	write(fd, ".", 1);
	if (percent % 100 < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(percent % 100, fd);
	write(fd, "%\n", 2);
}
