#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	int a, b, n;
	scanf("%d %d %d", &n, &a, &b);
	int x = 0;
	for (int i=1;i<n;i++) {
		int an = i;
		int bn = n-i;
		if (a < an || b < bn) continue;
		int k1 = a/an;
		int k2 = b/bn;
		x = max(x, min(k1, k2));
	}
	printf("%d\n", x);
    return 0;
}

