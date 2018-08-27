#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int main() {
	int n; scanf("%d", &n);
	set<ll> l, r, m;
	ll resp = 1ll;
	for (int i=0;i<n;i++) {
		string s; ll p;
		cin >> s >> p;
		if (s[1] == 'D') {
			if (l.size() != 0 && p < *l.rbegin()) {
				l.insert(p);
			}
			else if (r.size() != 0 && p > *r.begin()) {
				r.insert(p);
			}
			else {
				m.insert(p);
			}
		} else {
			if (l.size() != 0 && p == *l.rbegin()) {
				l.erase(l.find(p));
				for (auto a : m) {
					l.insert(a);
				}
			}
			else if (r.size() != 0 && p == *r.begin()) {
				r.erase(r.find(p));
				for (auto a : m) {
					l.insert(a);
				}
			}
			else if (m.find(p) != m.end()) {
				resp *= 2ll;
				resp %= mod;
				for (auto a : m) {
					if (a < p) l.insert(a);
					else if (a > p) r.insert(a);
				}
				m.clear();
			}
			else {
				resp = 0;
				break;
			}
		}
	}
	resp *= ll(m.size() + 1);
	resp %= mod;
	printf("%lld\n", resp);
    return 0;
}

