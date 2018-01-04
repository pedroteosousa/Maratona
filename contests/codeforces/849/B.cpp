#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int gcd(int a, int b) {
	if (a < 0) return gcd(-a, b);
	if (b < 0) return gcd(a, -b);
	if (b == 0) return a;
	return gcd(b, a%b);
}

int y[N];

pair<int, int> calc(int x1, int x2) {
	if (x1 > x2) return calc(x2, x1);
	pair<int, int> t = mp(x2-x1, y[x2]-y[x1]);
	int g = gcd(t.first, t.second);
	t = mp(t.first/g, t.second/g);
	return t;
}

int main() {
	int n;
	scanf("%d", &n);
	if (n <= 2) {
		printf("Yes\n");
		return 0;
	}
	for (int i=0;i<n;i++) {
		scanf("%d", &y[i]);
	}
	int ini = 0;
	for (int i=1;i<n;i++) {
		if (i == 1) ini = 2;
		else ini = 1;
		{
			pair<int, int> resp = calc(0, ini);
			if (calc(0, i) == resp) continue;
			int c1 = 1, c2 = 1, ok = 1;
			for (int j=1;j<n;j++) {
				if (j != i) {
					if (calc(j, i) != resp && calc(j, 0) != resp) {
						ok = 0;
						break;
					}
				}
			}
			if (ok) {
				printf("Yes\n");
				return 0;
			}
		}
		{
			pair<int, int> resp = calc(i, ini);
			if (calc(0, i) == resp) continue;
			int c1 = 1, c2 = 1, ok = 1;
			for (int j=1;j<n;j++) {
				if (j != i) {
					if (calc(j, i) != resp && calc(j, 0) != resp) {
						ok = 0;
						break;
					}
				}
			}
			if (ok) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}

