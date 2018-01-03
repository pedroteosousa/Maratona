#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e5 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int a[N];
int cont[N], resp[N];
vector<int> conn[N];

int change(int r, int sum) {
	for (int i=1;i*i <= a[r]; i++) {
		if (a[r]%i == 0) {
			cont[i]+=sum;
			if (i*i != a[r]) {
				cont[a[r]/i]+=sum;
			}
		}
	}
}

int best(int r, int prof) {
	for (int i=1;i*i <= a[0]; i++) {
		if (a[0]%i == 0) {
			if (cont[i] >= prof) resp[r] = max(resp[r], i);
			if (i*i != a[0]) {
				if (cont[a[0]/i] >= prof) resp[r] = max(resp[r], a[0]/i);
			}
		}
	}
	return 0;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

void dfs(int r, int prof = 0, int _gcd = 0) {
	change(r, 1);
	resp[r] = gcd(_gcd, a[r]);
	best(r, prof);
	for (auto b : conn[r]) {
		if (resp[b] == 0) dfs(b, prof+1, r==0 ? 0 : gcd(_gcd, a[r]));
	}
	change(r, -1);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	for (int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		conn[a].pb(b);
		conn[b].pb(a);
	}
	dfs(0);
	for (int i=0;i<n;i++) {
		printf("%d ", resp[i]);
	} printf("\n");
    return 0;
}

