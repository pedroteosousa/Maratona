#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int c[N];

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i=0;i<n;i++) {
		scanf("%d", &c[i]);
		sum += c[i];
	}
	int s = 0;
	int all = 0, id = 1, mn = inf;
	for (int i=0;i<n;i++) {
		s = 0;
		all = 0;
		for (int j=0;j<n;j++) {
			s += c[(i+j)%n];
			all = max(all, min(s, sum-s));
		}
		if (all < mn) {
			mn = all;
			id = i+1;
		}
	}
	printf("%d\n", id);
    return 0;
}

