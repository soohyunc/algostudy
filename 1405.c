#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
#define true  1
#define false 0
 
#define MAX 14
 
int N;
double P[4];
int v[MAX * 2][MAX * 2];
 
const int dr[] = { 1, -1, 0, 0 };
const int dc[] = { 0, 0, 1, -1 };
 
double crazyRobot(int r, int c, int n) {
	if (n == N)  return 1.0;
	if (v[r][c]) return 0.0;
 
	v[r][c] = true;
	double result = 0.0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
 
		if (!v[nr][nc])
			result += P[i] * crazyRobot(nr, nc, n + 1);
	}
	v[r][c] = false;
	return result;
}
 
int main() {
	scanf("%d", &N);
	scanf("%lf %lf %lf %lf", &P[0], &P[1], &P[2], &P[3]);
 
	for (int i = 0; i < 4; i++) {
		P[i] /= 100.;
	}
 
	printf("%.10lf\n", crazyRobot(MAX, MAX, 0));
	return 0;
}
