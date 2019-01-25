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
	int l, r, a; scanf("%d %d %d", &l, &r, &a);
	if (l > r) swap(l, r);
	int resp = l;
	resp += min(a, r-l);
	a -= min(a, r-l);
	resp += a/2;
	printf("%d\n", 2*resp);
    return 0;
}

