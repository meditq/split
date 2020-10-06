#include <stdlib.h>
#include <string.h>
#include "split.h"

int split(char *str, char ***list){
	int n = 0;
	char *s = str, *t, **tmp;
	if(!str) return 0;
	*list = NULL;
	while(1){
		while(*s == ' ') s++;
		if(!*s) break;
		if(t = strchr(s, ' ')) *t = '\0';
		tmp = realloc(*list, sizeof(char *) * (n + 1));
		if(!tmp) break;
		tmp[n++] = s;
		*list = tmp;
		if(!t) break;
		s = t + 1;
	}
	return n;
}

