#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

const int N = 1e5 + 5;
const int inf = 1791791791;

map<int, long long> m, v;
set<int> s;

long long f(int val, long long cap) {
	if (m[val] + v[val] <= cap) {
		if (val == 1) return 0;
		set<int>::iterator it = s.upper_bound(val-1);
		if (it == s.begin()) return 0;
		else {
			it--;
			return f(*it, cap);
		}
	} else {
		if (val == 1) return -1;
		if ((m[val]+v[val]) >= 2ll*cap) return -1;
		long long resp = (m[val]+v[val])-cap;
		v[val-1] = 2ll*resp;
		long long k = f(val-1, cap);
		if (k == -1) return -1;
		return resp + k;
	}
}

int main() {
	int n; scanf("%d", &n);
	int mx = 0;
	for (int i=0;i<n;i++) {
		int a; scanf("%d", &a);
		m[a]++;
		s.insert(a);
		mx = max(mx, a);
	}
	if (mx == 1) {
		printf("0\n");
		return 0;
	}
	long long base = 0ll;
	long long resp = 1000000000000000000ll;
    for (int i=0;i<20;i++) {
		if (mx == 1) {
			resp = min(resp, base);
			break;
		}
		v.clear();
		long long k = f(mx-1, m[mx]);
		//printf("cap = %lld, mx = %d, k = %lld, base = %lld, k+base=%lld, resp = %lld\n", m[mx], mx, k, base, k+base, resp);
		if (k != -1) resp = min(resp, base+k);
		m[mx-1] += 2ll*m[mx];
		base += m[mx];
		mx--;
	}
	printf("%lld\n", resp);
	return 0;
}

