#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int v[N];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i=0;i<n;i++) {
		scanf("%d", &v[i]);
	}
	sort(v, v+n);
	if (k == 0 && v[k] != 1) printf("1\n");
	else if (k != 0 && (k == n || v[k-1] < v[k])) printf("%d\n", v[k-1]);
	else printf("-1\n");
    return 0;
}

