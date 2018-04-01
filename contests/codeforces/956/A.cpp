#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

long long p[N];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0;i<n;i++) {
		string s; 
		cin >> s;
		for (int j=0;j<m;j++) {
			if (s[j] == '#') p[i] |= (1ll<<j);
		}
		//printf("p = %lld\n", p[i]);
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			//printf("%lld %lld %lld\n", p[i], p[j], p[i] & p[j]);
			if ((p[i] & p[j]) != 0 && ((p[i]&p[j]) != p[i] || (p[i]&p[j]) != p[j])) {
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
    return 0;
}

