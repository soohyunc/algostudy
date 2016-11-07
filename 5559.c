/*
* https://www.acmicpc.net/problem/5559
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define true  1
#define false 0

#define Max 20

typedef struct _n {
	int m;
	int n;
} BLANK;
BLANK spot[Max];

int N, M;
int R;		// number of '?'

char flag[Max][Max];

void __init__() {
	for (int i = 0; i < Max; i++) {
		spot[i].m = spot[i].n = 0;
		for (int j = 0; j < Max; j++) {
			flag[i][j] = '0';
		}
	}
}

int main() {
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++) {
		scanf("%s", flag[i]);
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (flag[i][j] == '?') {
				spot[R].m = i;
				spot[R].n = j;
				R++;
			}
		}
	} //printf("%d\n", R);

	perm(4, R);

	return 0;
}
