#include "split.h"
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char *str, **list, *p;
	int i, n;

	printf("Test program for libsplit\nCopyright (c) 2020 medit\n\n");
	while(1){
		str = readline("str> ");
		n = split(str, &list);
		if(n > 0){
			if(!strcmp(list[0], "exit")) break;
			for(i = 0; i < n; i++) printf("%2d: %s\n", i, list[i]);
		}
		free(list);
		free(str);
	}
	return 0;
}
