#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int a[N];

int main() {
	int n;
	scanf("%d", &n);
	int mn = mod;
	for (int i=0;i<n;i++) {
		scanf("%d", &a[i]);
		mn = min(mn, a[i]);
	}
	int last = -mod;
	int dist = mod;
	for (int i=0;i<n;i++) {
		if (a[i] == mn) {
			dist = min(dist, i-last);
			last = i;
		}
	}
	printf("%d\n", dist);
    return 0;
}

