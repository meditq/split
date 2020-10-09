#include "split.h"
#include <stdlib.h>
#include <string.h>

int split(char *str, char ***list){
	int n = 0;
	char *t, **tmp;
	*list = NULL;
	if(str == NULL) return 0;
	while(1){
		while(*str == ' ') str++;
		if(*str == '\0') break;
		t = strchr(str, ' ');
		if(t != NULL) *t = '\0';
		tmp = (char **)realloc(*list, sizeof(char *) * (n + 1));
		if(tmp == NULL) break;
		tmp[n++] = str;
		*list = tmp;
		if(t == NULL) break;
		str = t + 1;
	}
	return n;
}

