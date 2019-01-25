#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int a[N];
void brute(int n) {
	set<int> o, f;
	for (int i=0;i<3*n;i++) a[i] = 0;
	for (int i=1;i<=n;i++) {
		a[2*i-1] = i;
	}
	int last = 2*n-1;
	for (; last >= 1; last--) {
		if (a[last] != 0) {
			int i = last;
			while (a[i] != 0) {
				i--;
			}
			if (i != 0) swap(a[i], a[last]);
		}
	}
	for (int i=1;i<=n;i++) {
		printf("%d ", a[i]);
	} printf("\n");
}

long long f(long long pos, long long n) {
	if (pos % 2) return pos;
	else return f(n + pos/2, n);
}

int main() {
    long long n;
	int q;
	scanf("%lld %d", &n, &q);
	while (q--) {
		long long k; scanf("%lld", &k);
		printf("%lld\n", (f(k, n)+1ll)/2ll);
	}
	return 0;
}

