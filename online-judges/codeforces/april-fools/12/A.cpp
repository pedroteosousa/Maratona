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
	int a, b;
	scanf("%d %d", &a, &b);
	int c = 0;
	while (b != 0) {
		c *= 10;
		c += b%10;
		b /= 10;
	}
	printf("%d\n", a + c);
    return 0;
}

