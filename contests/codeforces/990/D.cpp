#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 1e3 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int mat[N][N];

int main() {
	int n, a, b; scanf("%d %d %d", &n, &a, &b);
	if (min(a, b) != 1) {
		printf("NO\n");
		return 0;
	}
	int c = max(a, b)-1;
	if (c == 0 && n <= 3 & n > 1) {
		printf("NO\n");
		return 0;
	}
	if (c == 0) {
		for (int i=0;i<n-1;i++) {
			mat[i][i+1] = mat[i+1][i] = 1;
		}
	}
	else {
		for (int i=c;i<n;i++) {
			for (int j=i+1;j<n;j++) {
				mat[i][j] = mat[j][i] = 1;
			}
		}
	}
	printf("YES\n"); // BURRO
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (i == j) printf("0");
			else if (a == c+1) printf("%d", mat[i][j]);
			else printf("%d", mat[i][j] ^ 1);
		} printf("\n");
	}
    return 0;
}

