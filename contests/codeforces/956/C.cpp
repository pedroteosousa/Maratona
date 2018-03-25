#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int mn[N];
int v[N];

int main() {
	int n; scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &v[i]);
	}
	int k = 0;
	for (int i=n-1;i>=0;i--) {
		k = max(k, v[i]+1);
		mn[i] = k;
		k--;
	}
	long long resp = 0;
	for (int i=1;i<n;i++) {
		mn[i] = max(mn[i], mn[i-1]);
		resp += mn[i] - v[i] - 1;
	}
	printf("%lld\n", resp);
    return 0;
}

