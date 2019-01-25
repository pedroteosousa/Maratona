#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

map<long long, pair<long long, map<pair<long long, long long>, long long> > > m;

int main() {
	int n; long long a, b; scanf("%d %lld %lld", &n, &a, &b);
	while (n--) {
		long long x, vx, vy; scanf("%lld %lld %lld", &x, &vx, &vy);
		m[a*vx-vy].first ++;
		m[a*vx-vy].second[mp(vx, vy)]++;
	}
	long long resp = 0;
	for (auto a : m) {
		resp += a.second.first*(a.second.first-1ll);
		for (auto b : a.second.second) {
			resp -= (b.second)*(b.second-1ll);
		}
	}
	printf("%lld\n", resp);
    return 0;
}

