#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BufferSize 8

int good_echo()
{
	char* buffer = (char*)calloc(BufferSize,sizeof(char));
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: failed to allocate buffer.\n");
		return -1;
	}
	while (1)
	{
		fgets(buffer, BufferSize, stdin);
		if (strlen(buffer) == BufferSize - 1)
		{
			fputs(buffer, stdout);
			if (buffer[BufferSize - 1 - 1] == '\n')
			{
				break;
			}
			memset(buffer, 0, strlen(buffer));
		}
		else if (strlen(buffer) < BufferSize - 1)
		{
			fputs(buffer, stdout);
			break;
		}
	}
	free(buffer);
	return 0;
}
int main()
{
	good_echo();
}

