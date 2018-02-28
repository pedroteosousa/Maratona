#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

const int N = 1e5 + 5;
const int inf = 1791791791;

int main() {
	int c1 = 0, c0 = 0;
	int n; scanf("%d", &n);
	set<int> s; s.insert(0);
	int mn = 0, mx = 0;
	while (n--) {
		int a; scanf("%d", &a);
		if (a == 0) c0++;
		if (a == 1) c1++;
		int t = c0-c1;
		mn = min(mn, t); mx = max(mx, t);
		int nmn = *s.begin();
		int nmx = *s.rbegin();
		mx = max(mx, t-nmn);
		mn = min(mn, t-nmx);
		s.insert(t);
	}
	int resp = mx - mn + 1;
	printf("%d\n", resp);
    return 0;
}

