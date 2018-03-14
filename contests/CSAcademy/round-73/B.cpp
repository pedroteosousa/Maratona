#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int h[N];

int main() {
	int n; scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &h[i]);
	}
	sort(h, h+n);
	int p = h[(n-1)/2];
	long long resp = 0;
	for (int i=0;i<n;i++) {
		if (h[i] <= p) resp += p-h[i];
		else resp += h[i]-p;
	}
	printf("%lld\n", resp);
    return 0;
}

