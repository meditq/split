#include <stdlib.h>
#include <string.h>
#include "split.h"

int split(char *str, char ***list){
	int n = 0;
	char *t, **tmp;
	if(!str) return 0;
	*list = NULL;
	while(1){
		while(*str == ' ') str++;
		if(!*str) break;
		if(t = strchr(str, ' ')) *t = '\0';
		tmp = realloc(*list, sizeof(char *) * (n + 1));
		if(!tmp) break;
		tmp[n++] = str;
		*list = tmp;
		if(!t) break;
		str = t + 1;
	}
	return n;
}

