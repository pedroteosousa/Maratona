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
	long long n;
	scanf("%lld", &n);
	long long m = 0;
	long long k = n;
	while (k) {
		m *= 10;
		m += k%10;
		k/=10;
	}
	if (n < m) printf("1\n");
	else printf("0\n");
    return 0;
}

