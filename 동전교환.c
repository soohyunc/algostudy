#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM 10
#define MAX 64001

int val[NUM];
int N[MAX];

int partition(int a[], int p, int r) {
	int tmp = 0;
	int pivot = a[r];
	int smallPos = p - 1;

	for (int i = p; i < r; i++) {
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

void quickSort(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quickSort(a, p, q - 1);
		quickSort(a, q + 1, r);
	}
}

int main(void) {
	int numCoin = 0;
	int money = 0;

	scanf("%d", &numCoin);
	for (int i = 0; i < numCoin; i++) {
		scanf("%d", &val[i]);
	}
	scanf("%d", &money);

	// optional (i.e., you can simply apply bubblesort)
	quickSort(val, 0, numCoin - 1);

	for (int i = 1; i < MAX; i++) {
		N[i] = MAX;
		for (int j = 0; j < numCoin; j++) {
			if (i < val[j])
				break;
			if (N[i] > N[i - val[j]] + 1)
				N[i] = N[i - val[j]] + 1;
		}
	}

	if (N[money] == MAX)
		printf("impossible\n");
	else
		printf("%d\n", N[money]);

	return 0;
}

