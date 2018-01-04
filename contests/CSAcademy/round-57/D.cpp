#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

const int N = 1e5 + 5;
const int inf = 1791791791;
const long long mod = 1000000007;

char s[300];

set<int> pos[N];

map<pair<int, int>, long long> m;

long long calc(int l, int r) {
	if (m.find(make_pair(l, r)) != m.end()) return m[make_pair(l, r)];
	long long sum = 0;
	for (int i='a';i<='z';i++) {
		set<int>::iterator it = pos[i].upper_bound(l);
		if (it == pos[i].end() || *it >= r) {
			continue;
		}
		int nl = *it;
		it = pos[i].lower_bound(r);
		it--;
		int nr = *it;
		sum += calc(nl, nr);
		sum %= mod;
	}
	return m[make_pair(l, r)] = (sum + 2)%mod;
}

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int i=0;i<n;i++) {
		pos[(int)s[i]].insert(i);
	}
	long long resp = 0;
	for (int i='a';i<='z';i++) {
		if ((int)pos[i].size()) {
			resp += calc(*pos[i].begin(), *pos[i].rbegin());
			resp %= mod;
		}
	}
	printf("%lld\n", resp);
	return 0;
}


