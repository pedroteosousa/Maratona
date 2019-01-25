#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	long long x, y; scanf("%lld %lld", &y, &x);
	if (x == 1 && y > 0) {
		printf("No\n");
		return 0;
	}
	if (x == 0) {
		printf("No\n");
		return 0;
	}
    y -= (x-1);
	if (y%2 == 0 && y >= 0) {
		printf("Yes\n");
	} else printf("No\n");
	return 0;
}

