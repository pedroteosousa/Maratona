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
	while (k--) {
		if (n%10) n--;
		else n/=10;
	}
	printf("%d\n", n);
    return 0;
}

