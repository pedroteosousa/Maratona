#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

set<pair<int, int> > e, b;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int l, r; scanf("%d %d", &l, &r);
			b.insert(mp(l, r));
			e.insert(mp(r, l));
		} else if (t == 2) {
			int l, r; scanf("%d %d", &l, &r);
			b.erase(mp(l, r));
			e.erase(mp(r, l));
		} else {
			int l, r; scanf("%d %d", &l, &r);
			int l1, r1; scanf("%d %d", &l1, &r1);
			if (l1 == l && r1 == r) {
				printf("0\n");
			}
			else if (r >= l1 && l <= r1) {
				int lm = min(l, l1);
				int rm = max(r, r1);
				set<pair<int, int> >::iterator it;
				it = b.upper_bound(mp(rm+1, 0));
				if (it != b.end()) {
					printf("2\n");
				} else {
					it = e.lower_bound(mp(lm-1, inf));
					if (it != e.begin()) {
						printf("2\n");
					} else printf("-1\n");
				}
			} else {
				printf("1\n");
			}
		}
	}
    return 0;
}

