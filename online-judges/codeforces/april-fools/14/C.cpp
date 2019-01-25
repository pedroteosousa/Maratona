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
	int n[5];
	int v[5] = {1,1,2,7,4};
	long long resp = inf;
	for (int i=0;i<5;i++) {
		scanf("%d", &n[i]);
		resp = min(resp, (ll)n[i]/(ll)v[i]);
	}
	printf("%lld\n", resp);
    return 0;
}

