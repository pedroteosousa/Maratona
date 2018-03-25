#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

vector<long long> v;

int main() {
	double resp = -10.0;
	int n; long long u; scanf("%d %lld", &n, &u);
	for (int i=0;i<n;i++) {
		long long e;
		scanf("%lld", &e);
		v.push_back(e);
	}
	for (int i=0;i<n-2;i++) {
		int k = upper_bound(v.begin(), v.end(), v[i]+u) - v.begin();
		k--;
		if (i+2 <= k) {
			resp = max(resp, (double)(v[k]-v[i+1])/(double)(v[k]-v[i]));
		}
	}
	if (resp >= -1.0) printf("%.10lf\n", resp);
	else printf("-1\n");
    return 0;
}

