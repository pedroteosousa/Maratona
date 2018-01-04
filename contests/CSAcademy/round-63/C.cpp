#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int a[N], b[N];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	int mx = 0;
	int g = 0;
	int wrong = 0;
	for (int i=0;i<n;i++) {
		scanf("%d", &b[i]);
		a[i] -= b[i];
		if (a[i] < 0) {wrong = 1; break;}
		g = gcd(g, a[i]);
		mx = max(mx, b[i]);
	}
	if (wrong) {
		printf("-1\n");
		return 0;
	}
	long long mn = g;
	for (long long i=1;i*i<=(long long)g;i++) {
		if (g%i == 0) {
			if (i > mx) mn = min(mn, i);
			if ((long long)g/i > mx) mn = min(mn, (long long)g/i);
		}
	}
	if (g == 0) printf("%d\n", mx+1);
	else if (g <= mx) printf("-1\n");
	else printf("%lld\n", mn);
    return 0;
}

