#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

struct f {
	long long n;
	int b3, b2;
};

bool cmp(const f &a, const f &b) {
	if (a.b3 > b.b3) return true;
	else if (a.b3 == b.b3) return (a.b2 < b.b2);
	else return false;
}

f v[N];

int main() {
	int n; scanf("%d", &n);
	for (int i=0;i<n;i++) {
		long long k;
		scanf("%lld", &v[i].n);
		k = v[i].n;
		v[i].b2 = v[i].b3 = 0;
		while (k % 3ll == 0) {
			k /= 3ll;
			v[i].b3++;
		}
		while (k % 2ll == 0) {
			k /= 2ll;
			v[i].b2++;
		}
	}
	sort(v, v+n, cmp);
	for (int i=0;i<n;i++) {
		printf("%lld ", v[i].n);
	} printf("\n");
    return 0;
}

