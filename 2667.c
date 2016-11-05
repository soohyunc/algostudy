#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define true  1
#define false 0

#define nMax 25

char map[nMax][nMax];
int  v[nMax][nMax];
int  dan[nMax];

int N, count, dcount;

void __init__() {
	N = count = dcount = 0;
	for (int i = 0; i < nMax; i++) {
		dan[i] = 0;
		for (int j = 0; j < nMax; j++) {
			map[i][j] = '0';
			v[i][j] = false;
		}
	}
}

void DFS(int r, int c) {
	if (v[r][c] || map[r][c] == '0') return;

	v[r][c] = true;
	count++;
	if (r + 1 < N)  DFS(r + 1, c);
	if (r - 1 >= 0) DFS(r - 1, c);
	if (c + 1 < N)  DFS(r, c + 1);
	if (c - 1 >= 0) DFS(r, c - 1);
}

void sort(int n) {
	int t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dan[i] < dan[j]) {
				t = dan[i];
				dan[i] = dan[j];
				dan[j] = t;
			}
		}
	}
}

int main() {
	__init__();
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			count = 0;
			DFS(i, j);

			if (count != 0) {
				dan[dcount++] = count;
			}
		}
	}

	sort(dcount);

	printf("%d\n", dcount);
	for (int i = 0; i < dcount; i++)
		printf("%d\n", dan[i]);

	return 0;
}
