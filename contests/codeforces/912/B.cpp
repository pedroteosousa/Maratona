#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	long long n, k;
	scanf("%lld %lld", &n, &k);
	long long n2 = n;
	long long g = 0;
	while (n) {
		g++;
		n >>= 1ll;
	}
    if (k == 1) printf("%lld\n", n2);
	if (k >= 2) printf("%lld\n", (1ll<<g)-1ll);
	return 0;
}

