
#include <stdio.h>

int main() {
	char ch;
	int len = 0;
	printf("Enter a message: ");
	ch = getchar();
	while (ch != '\n')
	{
		len++;
		ch = getchar();
	}
	printf("Length of the message: %d\n", len);
	return 0;
}











