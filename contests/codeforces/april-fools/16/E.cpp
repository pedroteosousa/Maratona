#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;

int m[10][10];

int loop2(int i, int j, int n) {
	scanf("%d", &m[j][i]);
	m[j][i] = ((j == i) ? inf : m[j][i]);
	i < n-1 ? loop2(i+1, j, n) : 0;
	return 0;
}

int loop1(int i, int n) {
	loop2(0, i, n);
	i < n-1 ? loop1(i+1, n) : 0;
	return 0;
}

int resp = 0;

int loop3(int i, int j, int k, int n) {
	m[k][i] = min(m[k][i], m[k][j]+m[j][i]);
	i < n-1 ? loop3(i+1, j, k, n) : 0;
	return 0;
}
int loop4(int i, int j, int n) {
	loop3(0, j, i, n);
	i < n-1 ? loop4(i+1, j, n) : 0;
	return 0;
}
int loop5(int i, int n) {
	loop4(0, i, n);
	i < n-1 ? loop5(i+1, n) : 0;
	return 0;
}

int loop21(int i, int j, int n) {
	int k = ((j == i) ? 0 : m[j][i]);
	resp = max(resp, k);
	i < n-1 ? loop21(i+1, j, n) : 0;
	return 0;
}

int loop11(int i, int n) {
	loop21(0, i, n);
	i < n-1 ? loop11(i+1, n) : 0;
	return 0;
}

int main() {
	int n; scanf("%d", &n);
	loop1(0, n);
	loop5(0, n);
	loop11(0, n);
	printf("%d\n", resp);
	return 0;
}

