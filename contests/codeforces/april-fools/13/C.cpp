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
	int tux;
	scanf("%d", &tux);
	int foo = 0, bar = 0, baz = 0, quz = 1;
	for (;tux > 0; tux--) {
		int pur;
		scanf("%d", &pur);
		foo += pur;
		bar += 1;
		if (max(foo*quz, bar*baz) == foo*quz) {
			baz = foo;
			quz = bar;
		}
	}
	printf("%lf\n", (double)baz/(double)quz);
    return 0;
}

