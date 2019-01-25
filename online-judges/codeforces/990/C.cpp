#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

map<int, ll> m;

int main() {
	int n; scanf("%d", &n);
	ll resp = 0;
	while (n--) {
		string s; cin >> s;
		int p = 0;
		int mn = 0;
		for (auto c : s) {
			if (c == '(') p++;
			else p--;
			mn = min(mn, p);
		}
		if (mn == 0 && p >= 0) {
			m[p]++;
		} else if (mn == p) {
			m[p]++;
		}
	}
	for (auto a : m) {
		if (a.first >= 0) {
			resp += a.second * m[-a.first];
		}
	}
	printf("%lld\n", resp);
    return 0;
}

