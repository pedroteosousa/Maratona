#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1791791791;

#define pb push_back

long double f(int k, int r, int w) {
	if ((1<<k) - r - (1<<w) + 1 < 0) return 0.0;
	int up1 = (1<<k) - (1<<w);
	int up2 = (1<<k) - r;
	int down1 = (1<<k);
	int down2 = (1<<k) - r - (1<<w) + 1;
	long double resp = (long double)(1<<k);
	while((up1 || up2) && (down1 || down2)) {
		if (resp <= 1.0) {
			if (up1) resp *= (long double)(up1--);
			else if (up2) resp *= (long double)(up2--);
		}
		else {
			if (down1) resp /= (long double)(down1--);
			else if (down2) resp /= (long double)(down2--);
		}
	}
	while(up1 || up2) {
		if (up1) resp *= (long double)(up1--);
		else if (up2) resp *= (long double)(up2--);
	}
	while(down1 || down2) {
		if (down1) resp /= (long double)(down1--);
		else if (down2) resp /= (long double)(down2--);
	}
	return resp;
}

long double v[N];

int main() {
	int k, r;
	scanf("%d %d", &k, &r);
	long double resp = 0;
	for (int i=0;i<=k;i++) v[i] = f(k, r, i);
	for (int i=k-1;i>=1;i--) {
		resp += (long double)i*(v[i] - v[i+1]);
	}
	printf("%.5Lf\n", resp + (long double)k*v[k]);
	return 0;
}

