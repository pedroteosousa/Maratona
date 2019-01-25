#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 2e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int v[N][2];

int main() {
	int n, m; scanf("%d %d", &n, &m);	
	for (int i=0;i<n;i++) {
		scanf("%d", &v[i][0]);
	}
	for (int i=0;i<m;i++) {
		scanf("%d", &v[i][1]);
	}
	int p1, p2;
	p1 = p2 = 0;
	long long s1, s2;
	s1 = s2 = 0;

	int resp = 0;
	while (p1 < n || p2 < m) {
		if (s2 < s1) {
			s2 += v[p2++][1];
		} else {
			s1 += v[p1++][0];
		}
		if (s1 == s2) resp++; 
	}
	printf("%d\n", resp);
    return 0;
}

