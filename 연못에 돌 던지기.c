/*
 * http://hackerslab.eu/blog/2016/11/%EC%97%B0%EB%AA%BB%EC%97%90-%EB%8F%8C-%EB%8D%98%EC%A7%80%EA%B8%B0/
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define _abs(x) (x > 0 ? (x) : -(x))

#define true	1
#define false	0

#define nMax	16
#define mMax	4
#define MAX	1000

typedef struct __f {
	int Id;
	int X;
	int Y;
	int E;
} Flower;

typedef struct __s {
	int X;
	int Y;
	int E;
} Stone;

Flower	flower[nMax], copy[nMax];
Stone	stone[mMax];

int N, M;
int P, R;
int numSink;
int E[nMax];

void __init__() {
	N = M = P = R = 0;
	numSink = 0;
	for (int i = 0; i < nMax; i++) {
		E[i] = 0;
		flower[i].Id = flower[i].X = flower[i].Y = flower[i].E = 0;
	}
	for (int i = 0; i < mMax; i++) {
		stone[i].X = stone[i].Y = 0;
	}
}

void _restore() {
	for (int i = 0; i < N; i++) {
		flower[flower[i].Id].E = E[flower[i].Id];
	}
}

void _copy() {
	for (int i = 0; i < N; i++) {
		E[i] = flower[i].E;
	}
}

int _dist(Stone A, Flower B) {
	return _abs(A.X - B.X) + _abs(A.Y - B.Y);
}

void swap(int a, int b) {
	int x = flower[a].X;
	int y = flower[a].Y;
	int e = flower[a].E;

	flower[a].X = flower[b].X;
	flower[a].Y = flower[b].Y;
	flower[a].E = flower[b].E;

	flower[b].X = x;
	flower[b].Y = y;
	flower[b].E = e;
}

int isInvalid(int n) {
	int invalid = false;

	for (int j = 0; j < N; j++) {
		if (stone[n].X == flower[j].X && stone[n].Y == flower[j].Y) {
			if (flower[j].E <= 0)
				invalid = true;
		}
	}

	return invalid;
}

void calculate(int count) {
	for (int i = 0; i < M; i++) {
		//printf("%d %d ", stone[i].X, stone[i].Y);

		if (!isInvalid(i)) {
			for (int j = 0; j < N; j++) {
				if (_dist(stone[i], flower[j]) <= R && flower[j].E > 0) {
					flower[j].E -= P;
				}

				if (flower[j].E <= 0)
					count++;
			}
		}
	} //printf("\n");
	  //printf("count = %d\n", count);

	if (count > numSink)
		numSink = count;
}

void repeated_perm(int n, int r) {
	if (r == 0) {
		calculate(0);
		_restore();
		return;
	}

	for (int i = 0; i < n; i++) {
		swap(i, n - 1);
		stone[r - 1].X = flower[n - 1].X;
		stone[r - 1].Y = flower[n - 1].Y;
		repeated_perm(n, r - 1);
		swap(i, n - 1);
	}
}

int main(void)
{
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		__init__();
		scanf("%d", &N);
		//printf("%d\n", N);
		for (int i = 0; i < N; i++) {
			flower[i].Id = i;
			scanf("%d %d %d", &flower[i].X, &flower[i].Y, &flower[i].E);
		}
		_copy();
		scanf("%d %d %d", &M, &P, &R);
		//printf("%d\n", M);

		repeated_perm(N, M);
		printf("#%d %d\n", test_case, N - numSink);
	}
	return 0;
}
