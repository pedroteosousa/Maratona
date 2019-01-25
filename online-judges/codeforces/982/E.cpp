#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

bool col(int n, int m, int x, int y, int vx, int vy) {
	
}

int main() {
	int n, m, x, y, vx, vy;
	scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &vx, &vy);
	if (vx == 0) {
		if (x == 0 || x == n) {
			if (vy > 0) printf("%d %d\n", x, m);
			else printf("%d %d\n", x, 0);
			return 0;
		} else {
			printf("-1\n");
			return 0;
		}
	} else if (vy == 0) {
		if (y == 0 || y == m) {
			if (vx > 0) printf("%d %d\n", n, y);
			else printf("%d %d\n", 0, y);
			return 0;
		} else {
			printf("-1\n");
			return 0;
		}
	} else {
		int k = gcd(n, m);
		
	}
    return 0;
}

