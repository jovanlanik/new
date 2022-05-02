// New
// Copyright (c) 2022 Jovan Lanik, Josef Miegl

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char map[][5] = {
	"/\\",
	"|:",
	"[",
	"|]",
	"[-",
	"|=",
	"[.",
	"|-|",
	"|",
	".|",
	"|<",
	"|.",
	"|\\/|",
	"|\\|",
	"[]",
	"|>",
	"[|.",
	"|>.",
	"./",
	"-|-",
	"||",
	"\\/",
	"\\\\/",
	"><",
	"^/",
	"/.",
};

#define LEN(c) strlen(map[toupper(c)-'A'])
#define MAP(c, i) map[toupper(c)-'A'][i]

int main(int argc, char *argv[]) {
	char input[3];
	for(int i = 0; i < 2; ++i) input[i] = '\0';
	while(input[2] != EOF) {
		input[2] = getchar();
		if(input[2] == '\033') {
			while(input[1] != 'm') {
				putchar(input[2]);
				for(int i = 1; i < 3; ++i) input[i-1] = input[i];
				input[2] = getchar();
			}
		}
		if(isalpha(input[2])) {
			for(int i = 0; i < LEN(input[2]); ++i) {
				if(input[1] == '\b') {
					if(input[0] == '_') {
						putchar(MAP(input[2], i));
						if(i == LEN(input[2])-1) break;
						putchar('_');
						putchar('\b');
					}
					else {
						putchar(MAP(input[2], i));
						putchar('\b');
						putchar(MAP(input[2], i));
					}
				}
				else putchar(MAP(input[2], i));
			}
		}
		else if(input[2] == '\b') {
			if(!isalpha(input[1])) putchar('\b');
			else for(int i = 0; i < LEN(input[1]); ++i) putchar('\b');
		}
		else putchar(input[2]);
		for(int i = 1; i < 3; ++i) input[i-1] = input[i];
	}
	return 0;
}

