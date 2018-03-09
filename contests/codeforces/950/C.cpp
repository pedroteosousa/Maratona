#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

vector<vector<int> > v;
set<int> a, b;

int main() {
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++) {
		if (s[i] == '0') a.insert(i+1);
		else b.insert(i+1);
	}
	while (a.size() || b.size()) {
		int p = 0, g = 0;
		vector<int> t;
		while (true) {
			if (p % 2 == 0) {
				set<int>::iterator it = a.upper_bound(g);
				if (it == a.end()) {
					break;
				} else {
					g = *it;
					t.pb(g);
					a.erase(g);
				}
			} else {
				set<int>::iterator it = b.upper_bound(g);
				if (it == b.end()) {
					break;
				} else {
					g = *it;
					t.pb(g);
					b.erase(g);
				}
			}
			p++;
		}
		if (p % 2 == 0) {
			printf("-1\n");
			return 0;
		} else {
			v.pb(t);
		}
	}
	printf("%d\n", (int)v.size());
	for (auto t : v) {
		printf("%d ", (int)t.size());
		for (auto p : t) {
			printf("%d ", p);
		} printf("\n");
	}
	return 0;
}

