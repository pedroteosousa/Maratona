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
	int t; scanf("%d", &t);
	for (int i=1;i<=t;i++) {
		int n; scanf("%d", &n);
		vector<int> v[2];
		for (int j=0;j<n;j++) {
			int a; scanf("%d", &a);
			v[j%2].pb(a);
		}
		for (int j=0;j<2;j++) sort(v[j].begin(), v[j].end());
		printf("Case #%d: ", i);
		bool flag = true;
		for (int j=0;j<n-1;j++) {
			if (v[j%2][j/2] > v[(j+1)%2][(j+1)/2]) {
				printf("%d\n", j);
				flag = false;
				break;
			}
		}
		if (flag) printf("OK\n");
	}
    return 0;
}

