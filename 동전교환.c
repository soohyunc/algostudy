#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N   10
#define MAX_CNT 64001

int COIN[N];
int NumCoin[MAX_CNT];

int partition(int a[], int p, int r);
void quickSort(int a[], int p, int r);

int minCnt = MAX_CNT;
int numCoin = 0;

void main() {
	int i, j;
	int money = 0;
	int ret = 0;

	scanf("%d", &numCoin);

	for (i = 0; i < numCoin; i++) {
		scanf("%d", &COIN[i]);
	}
	scanf("%d", &money);

	quickSort(COIN, 0, numCoin - 1);

	for (i = 1; i < MAX_CNT; i++)
	{
		NumCoin[i] = MAX_CNT;
		for (j = 00; j < numCoin; j++) {
			if (i < COIN[j])
				break;
			if (NumCoin[i] > NumCoin[i - COIN[j]] + 1)
				NumCoin[i] = NumCoin[i - COIN[j]] + 1;
		}
	}

	if (NumCoin[money] == MAX_CNT)
		printf("impossible\n");
	else
		printf("%d\n", NumCoin[money]);
}

int partition(int a[], int p, int r)
{
	int tmp = 0;
	int pivot = a[r];
	int smallPos = p - 1;
	int i;

	for (i = p; i < r; i++) {
		if (pivot >= a[i]) {
			tmp = a[i];
			a[i] = a[++smallPos];
			a[smallPos] = tmp;
		}
	}

	tmp = a[r];
	a[r] = a[++smallPos];
	a[smallPos] = tmp;

	return smallPos;
}

void quickSort(int a[], int p, int r)
{
	if (p < r) {
		int q = partition(a, p, r);
		quickSort(a, p, q - 1);
		quickSort(a, q + 1, r);
	}
}
