#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	if (n > 32) {
		printf("%lld\n", m);
		return 0;
	}
	n = 1ll<<n;
	printf("%lld\n", m%n);
    return 0;
}

