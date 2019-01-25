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
	int n; scanf("%d", &n);
	int k1 = 0, k2 = 0;
	for (int i=0;i<n;i++) {
		char c; scanf(" %c", &c);
		if (c == '8') k1++;
		else k2++;
	}
	for (int i=100;i>=0;i--) {
		if (k1 >= i && (k2 + (k1 - i)) / 10 >= i) {
			printf("%d\n", i);
			return 0;
		}
	}
    return 0;
}

