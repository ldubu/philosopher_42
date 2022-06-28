#include <stdio.h>
int main(void)
{
	unsigned int i;

	i = (0 - 1) % 12;
	printf("i = %u\n", i);
	return (0);
}