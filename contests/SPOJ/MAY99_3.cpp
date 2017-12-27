#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		if ((z % gcd(x, y) == 0 && z <= max(x, y)) || (z == x || z == y)) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}

