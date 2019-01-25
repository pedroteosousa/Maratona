#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int v[20];

int main() {
	int n; scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &v[i]);		
	}
	while (n--) {
		int mx = 0;
		int id = 0;
		for (int i=0;i<n;i++) {
			if (abs(v[i]-v[i+1]) >= 2) {
				printf("NO\n");
				return 0;
			}
			if (mx < v[i]) {
				mx = v[i];
				id = i;
			}
		}
		if (mx < v[n]) {
			mx = v[n];
			id = n;
		}
		for (int i=id;i<n;i++) {
			v[i] = v[i+1];
		}
	}
	printf("YES\n");
    return 0;
}

