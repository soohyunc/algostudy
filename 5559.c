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
BLANK spot[Max], input[Max];

int N, M;
int R;		// number of '?'
int count;

char flag[Max][Max];

void __init__() {
	count = 0;
	for (int i = 0; i < Max; i++) {
		spot[i].m = spot[i].n = 0;
		input[i].m = input[i].n = 0;

		for (int j = 0; j < Max; j++) {
			flag[i][j] = '0';
		}
	}
}

void swap(int a, int b) {
	int tm = input[a].m;
	int tn = input[a].n;

	input[a].m = input[b].m;
	input[a].n = input[b].n;

	input[b].m = tm;
	input[b].n = tn;
}

void rollout() {
	
}

void _print() {
	for (int i = 0; i < R; i++) {
		printf("(%d %d) ", spot[i].m, spot[i].n);
	} printf("\n");
}

void PI(int n, int r) {
	if (r == 0) {
		_print();
		//rollout();
		return;
	}

	for (int i = 0; i < n; i++) {
		swap(i, n - 1);
		spot[r - 1] = input[n - 1];
		PI(n - 1, r - 1);
		swap(i, n - 1);
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
				input[R].m = i;
				input[R].n = j;
				R++;
			}
		}
	} //printf("%d\n", R);


	PI(3, R);

	printf("%d\n", count%100000);
	return 0;
}
