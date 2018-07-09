#include <fcntl.h>
#include "libfts.h"

int main()
{

	int fd = open("main.c", O_RDONLY);
/*
	char buffer[2048];
	char first[2048];
	bzero(buffer, 2048);
	bzero(first, 2048);
	int ret = read(fd, first, 50);
	printf("[%d]:%s\n", ret, first);
	ret = read(fd, buffer, 50);
	char *joined = ft_strjoin(first, buffer);
	printf("[%d]1:%s\n", ret, buffer);
	printf("joined:%s\n", joined);
	char *test2 = ft_strjoin("aaaaaaaaaaaaa", "bbbbbbbbbbbbbbb");
*/
	ft_cat(fd);
//	while (1);
	return 0;
}
