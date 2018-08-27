#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

typedef struct rect {
	int x1, y1, x2, y2;
	bool inside(pair<int, int> p) {
		if (x1 <= p.first && p.first <= x2 && y1 <= p.second && p.second <= y2) {
			return true;
		}
		return false;
	}
	bool inter(const struct rect &a) {
		struct rect b = get(a);
		return b.isOk();
	}
	struct rect get(const struct rect &a) {
		return {max(x1, a.x1), max(y1, a.y1), min(x2, a.x2), min(y2, a.y2)};
	}
	bool isOk() {
		if (x2 >= x1 && y2 >= y1) return true;
		return false;
	}
} rect;

vector<rect> v;
int number(rect it) {
	int count = 0;
	for (auto a : v) {
		if (a.inside(mp(it.x1, it.y1))) count++;
	}
	return count;
}

int main() {
	int n; scanf("%d", &n);
	set<int> x, y;	
	for (int i=0;i<n;i++) {
		rect a;
		scanf("%d %d %d %d", &a.x1, &a.y1, &a.x2, &a.y2);
		x.insert(a.x1);
		y.insert(a.y1);
		v.pb(a);
	}
	int v1 = -1;
	for (int i=0;i<n;i++) {
		if (x.upper_bound(v[i].x2) == x.end() && y.upper_bound(v[i].y2) == y.end()) {

		} else {
			v1 = i;
			break;
		}
	}
	rect i1 = {-inf, -inf, inf, inf};
	rect i2 = i1;
	int count = 0;
	for (int i=0;i<n;i++) {
		if (i != v1) {
			i1 = i1.get(v[i]);
		}
	}
	if (i1.isOk() && number(i1) >= n-1) {
		printf("%d %d\n", i1.x1, i1.y1);
		return 0;
	}
	for (int i=0;i<n;i++) {
		if (v[i].inter(i2)) i2 = i2.get(v[i]);
	}
	if (i2.isOk() && number(i2) >= n-1) {
		printf("%d %d\n", i2.x1, i2.y1);
		return 0;
	}
    return 0;
}

