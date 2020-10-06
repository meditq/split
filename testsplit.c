#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"

int main(void){
	char str[128], **list, *p;
	int i, n;

	printf("Test tool for libsplit\n\n");
	while(1){
		printf("str> ");
		if(fgets(str, sizeof(str), stdin)){
			p = strchr(str, '\n');
			if(!p) while((i = getchar()) != '\n' && i != EOF);
			else *p = '\0';
			n = split(str, &list);
			if(n > 0){
				if(!strcmp(list[0], "exit")) break;
				for(i = 0; i < n; i++) printf("%2d: %s\n", i, list[i]);
			}
			free(list);
		}else break;
	}
	return 0;
}
