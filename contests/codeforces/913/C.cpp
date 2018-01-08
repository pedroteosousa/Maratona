#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const long long inf = 5e18;
const int mod = 1e9+7;

long long val[50];

int main() {
	int n; long long l;
	scanf("%d %lld", &n, &l);
	for (int i=0;i<n;i++) {
		scanf("%lld", &val[i]);
	}
	for (int i=n;i<30;i++) {
		val[i] = inf;
	}
	for (int i=0;i<30;i++) {
		for (int j=i+1;j<30;j++) {
			if (val[j] > val[i]*(1ll<<((long long)(j-i)))) {
				val[j] = val[i]*(1ll<<((long long)(j-i)));
			}
		}
	}
	long long resp = 0;
	for (int i=0;i<30;i++) {
		if (l&1) {
			resp += val[i];
		} else {
			if (val[i] < resp) {
				resp = val[i];
			}
		}
		l >>= 1ll;
	}
	printf("%lld\n", resp);
    return 0;
}

