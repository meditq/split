# libsplit
文字列を分割するライブラリ

## How to build
`make libsplit`で静的ライブラリ(libsplit.a)が生成されます。

`make testsplit`でテスト用プログラムが生成されます。

## split(3)
### 名前
split - 文字列を分割する

### 書式
```
#include "split.h"

int split(char *str, char ***list);
```

### 説明
**split()** は、`str`が指す文字列をスペースで分割し、分割された各文字列の配列を`list`が指す場所に格納します。連続するスペースや先頭・末尾のスペースは無視されます。`list`によって返される配列はヒープ領域に確保されているため、使用後は **free(3)** を呼び出さなければなりません。この関数は`str`を破壊します。`str`が **malloc(3)** により割り当てられている場合、`str`は`list`より後に **free(3)** されなければなりません。

### 返り値
**split()** は、分割によって得られた文字列の個数を返します。また、`list`が指す場所には得られた文字列を指す char * 型ポインタの配列が格納されます。`str`がNULLの場合、または`str`が指す文字列がスペース以外の文字を含まない場合は0が返され、`list`が指す場所にはNULLが格納されます。

### 例
#### サンプルコード
```
#include "split.h"
#include <stdio.h>

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
Copyright (c) 2020 medit

### 関連項目
**testsplit(1)**

## testsplit(1)
### 名前
testsplit - libsplitのテスト用プログラム

### 書式
```testsplit```

### 説明
**testsplit** は、対話型シェルライクのプログラムです。入力された文字列を **split(3)** に通した結果を見やすく表示します。

`exit`とタイプするか、Ctrl-Cキーで終了できます。

### 著者
Copyright (c) 2020 medit

### 関連項目
**split(3)**

## ライセンス
All source codes in this repository are available under [MIT License](./LICENSE).
