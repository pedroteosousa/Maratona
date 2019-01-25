#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

multiset<int> a, b;

int main() {
	int n; scanf("%d", &n);	
	ll resp = n;
	for (int i=0;i<n;i++) {
		int x, y; scanf("%d %d", &x, &y);
		resp += (x + y);
		a.insert(x);
		b.insert(y);
	}
	while (n--) {
		int l = *a.rbegin();
		int r = *b.rbegin();
		a.erase(a.find(l));
		b.erase(b.find(r));
		resp -= min(l, r);
	}
	printf("%lld\n", resp);
    return 0;
}

