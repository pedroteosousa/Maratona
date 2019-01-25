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
				pair<int, int> p1 = *b.rbegin();
				pair<int, int> p2 = *e.begin();
				if (p1.first > rm || p2.first < lm) {
					printf("2\n");
				} else if ((p1.first > r && p2.first < l1) || (p1.first > r1 && p2.first < l)) {
					printf("3\n");
				} else {
					printf("-1\n");
				}
			} else {
				printf("1\n");
			}
		}
	}
    return 0;
}

