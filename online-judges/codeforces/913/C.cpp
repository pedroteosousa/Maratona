#include <bits/stdc++.h>
using namespace std;

const long long inf = 5e18;

long long val[50];

int main() {
	int n; long long l;
	scanf("%d %lld", &n, &l);
	for (int i=0;i<=30;i++) {
		if (i<n) scanf("%lld", &val[i]);
		else val[i] = inf;
		if (i > 0) val[i] = min(val[i], 2ll*val[i-1]);
	}
	long long resp = 0;
	for (int i=0;i<=30;i++) {
		if (l&1)
			resp += val[i];
		else if (val[i] < resp)
			resp = val[i];
		l >>= 1ll;
	}
	printf("%lld\n", resp);
    return 0;
}

