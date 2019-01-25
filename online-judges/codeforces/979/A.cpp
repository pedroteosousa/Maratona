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
	ll n; scanf("%lld", &n); n++;
	if (n%2ll == 0ll) printf("%lld\n", n/2ll);
	else if (n == 1ll) printf("0\n");
	else printf("%lld\n", n);
    return 0;
}

