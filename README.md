# libsplit
文字列を分割するライブラリ

## split(3)
### 名前
split - 文字列を分割する

### 書式
```
#include "split.h"

int split(char *str, char ***list);
```

### 説明
**split**()は、```str```が指す文字列をスペースで分割し、分割された各文字列の配列を```list```が指す場所に格納します。連続するスペースや先頭・末尾のスペースは無視されます。```list```によって返される配列はヒープ領域に確保されているため、使用後は**free**(3)を呼び出さなければなりません。この関数は```str```を破壊します。

### 戻り値
**split**()は、分割によって得られた文字列の個数を返します。また、```list```が指す場所には得られた文字列の配列が格納されます。```str```にNULLが与えられた場合または```str```がスペース以外の文字を含まない場合は0が返され、```list```が指す場所にはNULLが格納されます。

### 例
#### サンプルコード
```
#include <stdio.h>
#include "split.h"

int main(void){
	char str[] = "   medit   split test   ";
	char **list;
	int i, n;
	n = split(str, &list);
	for(i = 0; i < n; i++) printf("%2d: %s\n", i, list[i]);
	free(list);
	return 0;
}
```

#### 実行結果
```
 0: medit
 1: split
 2: test
```

### 著者
2020 medit.
