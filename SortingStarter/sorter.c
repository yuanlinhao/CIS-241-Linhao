#include "sorter.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* strdup(char*);


void swap(char**x, char**y) {
	char* z = *x;
	*x = *y;
	*y = z;
}


void QuickSortBase(char**Data, int L, int R) {
	if (L >= R) return;

	char* x = Data[L];
	int i = L, j = R;
	while (1) {
		while (strcmp(Data[i], x) < 0) ++i;
		while (j > i && strcmp(Data[j], x) >= 0) --j;
		if (i >= j) break;
		swap(&Data[i], &Data[j]);
	}

	if (i == L) {
		QuickSortBase(Data, i + 1, R);
	}
	else {
		QuickSortBase(Data, L, i - 1);
		QuickSortBase(Data, i, R);
	}
}


void QuickSort(char**Data, int N) {
	if (N >= 2) {
		QuickSortBase(Data, 0, N - 1);
	}
}


void init(char* tmp, char** arr, int* count)
{
	int flag = 0, idx = 0;
	for(int i = 0; tmp[i]; ++i) {
		if(tmp[i] == '\n' || tmp[i] == '\r') {
			tmp[i] = 0;
			flag = 0;
		}
		else if(!flag) {
			arr[idx++] = &tmp[i];
			flag = 1;
		}
	}
	*count = idx;
}


void save(char** arr, int count, char* buf)
{
	int pos = 0, first = 1;
	for(int i = 0; i < count; ++i) {
		if(!first) {
			buf[pos++] = '\n';
		}
		first = 0;
		
		int len = strlen(arr[i]);
		memcpy(buf + pos, arr[i], len);
		pos += len;
	}
	buf[pos] = 0;
}


void sort(char* content, int size)
{
	char* tmp = strdup(content);
	char** arr = (char**)malloc(size * sizeof(char*));
	int count = 0;
	
	init(tmp, arr, &count);
	QuickSort(arr, count);
	save(arr, count, content);
		
	free(arr);
	free(tmp);
}