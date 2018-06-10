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
	int n, k; scanf("%d %d", &n, &k);
	vector<int> v;
	for (int i=0;i<n;i++) {
		int a; scanf("%d", &a);
		v.pb(a);
	}
	sort(v.begin(), v.end());
	int resp = n;
	for (int i=0;i<n;i++) {
		int p = upper_bound(v.begin(), v.end(), v[i]+k) - v.begin();
		p--;
		if (p < n && v[i]+k >= v[p] && v[p] > v[i]) resp--;
	}
	printf("%d\n", resp);
    return 0;
}

