//
// New
// Copyright (c) 2018 Jovan Lanik, Josef Miegl
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char map[][5] = {"/\\", "|:", "[", "|]", "[-", "|=", "[.", "|-|", "|", ".|", "|<", "|.", "|\\/|",
		"|\\|", "[]", "|>", "[|.", "|>.", "./", "-|-", "||", "\\/", "\\\\/", "><", "^/", "/."};

int main(void)
{
	char input[3];
	for(int j = 0; j < 2; ++j)
	{
		input[j] = '\0';
	}
	while(input[2] != EOF)
	{
		input[2] = getchar();
		if(input[2] == '\033') while(input[2-1] != 'm')
		{
			putchar(input[2]);
			for(int j = 1; j < 3; ++j) {
				input[j-1] = input[j];
			}
			input[2] = getchar();
		}

		if(isalpha(input[2]))
		{
			for(int i = 0; i < strlen(map[toupper(input[2])-65]); ++i)
			{
				if(input[1] == '\b')
				{
					if(input[0] == '_')
					{
						putchar(map[toupper(input[2])-65][i]);
						if(i == strlen(map[toupper(input[2])-65])-1) break;
						putchar('_');
						putchar('\b');
					}
					else
					{
						putchar(map[toupper(input[2])-65][i]);
						putchar('\b');
						putchar(map[toupper(input[2])-65][i]);
					}
				}
				else putchar(map[toupper(input[2])-65][i]);
			}
		}
		else if(input[2] == '\b')
		{
			if(isalpha(input[1]))
			{
				for(int i = 0; i < strlen(map[toupper(input[1])-65]); ++i)
				{
					putchar('\b');
				}
			}
			else putchar('\b');
		}
		else putchar(input[2]);

		for(int j = 1; j < 3; ++j) {
			input[j-1] = input[j];
		}
	}
	return 0;
}
