#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int p[N];
void make_p(int n, int offset = 0) {
	if(n == 0) return;
	int k = 0;
	while (n - (1<<k) >= 0) k++;
	k--;
	int v = 1<<k;
	for (int i=1;i<=n-v+1;i++) {
		p[v - i + offset] = v + i - 1 + offset;
		p[v + i - 1 + offset] = v - i + offset;
	}
	make_p(2*v - n - 2, 0);
}

void q(int n) {
}

int main() {
	int n;
	scanf("%d", &n);
	if (n%2) printf("NO\n");
	else {
		printf("YES\n");
		make_p(n);
		for (int i=0;i<n;i++) printf("%d ", p[i+1]);
		printf("\n");
	}
	if (n<=5) printf("NO\n");
	else {
		int k = 0;
		while (n - (1<<k) >= 0) k++;
		k--;
		if ((1<<k) == n) printf("NO\n");
		else if (n == 6) {
			printf("YES\n");
			printf("3 6 2 5 1 4");
		}
		else {
			printf("YES\n");
			printf("7 3 6 5 1 2 4 ");
			for (int i=3;(1<<i)<=n;i++) {
				for (int j=(1<<i);j<min(n+1, (1<<(i+1)));j++) {
					int k = j+1;
					if (k >= min(n+1, (1<<(i+1)))) k = (1<<i);
					printf("%d ", k);
				}
			}
		}
	} printf("\n");
    return 0;
}

