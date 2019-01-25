#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int a[N], b[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	for (int i=0;i<m;i++) {
		scanf("%d", &b[i]);
	}
	int count = 0;
	for (int i=0;i<=m-n;i++) {
		int c = 0;
		for (int j=0;j<n;j++) {
			if (a[j] + b[j+i] == 1) c++;
		}
		if (c == n) count++;
	}
	printf("%d\n", count);
    return 0;
}

