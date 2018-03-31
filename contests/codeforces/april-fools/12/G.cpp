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
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while (c--) {
		int d = a+b;
		a = b;
		b = d;
	}
	printf("%d\n", a);
    return 0;
}

