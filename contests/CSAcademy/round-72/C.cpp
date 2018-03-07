#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

long long sum1[N];
long long sum2[N];

int main() {
	long long base = 0;
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			long long a; scanf("%lld", &a);

			long long mul = 1;
			if (j > 0 && j < m-1) {
				sum1[i] += 2ll*a;
				mul *= 2;
			} else {
				sum1[i] += a;
			}
			if (i > 0 && i < n-1) {
				sum2[j] += 2ll*a;
				mul *= 2;
			} else {
				sum2[j] += a;
			}
			base += mul*a;
		}
	}
	long long mx1 = max(sum1[0], sum1[n-1]);
	long long mx2 = max(sum2[0], sum2[m-1]);
	sum1[0] = sum2[0] = sum1[n-1] = sum2[m-1] = inf;
	sort(sum1, sum1 + n);
	sort(sum2, sum2 + m);
    //printf("%lld %lld %lld %lld %lld\n", base, mx1, mx2, sum1[0], sum2[0]);
	long long bs = base;
	base = max(base, bs + (mx1 - sum1[0]));
	base = max(base, bs + (mx2 - sum2[0]));
    printf("%lld\n", base);
	return 0;
}

