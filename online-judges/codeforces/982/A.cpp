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
	int n; scanf("%d", &n); getchar();
	for (int i=1;i<=n;i++) {
		char c; scanf("%c", &c);
		if (c == '0') v[i] = 0;
		else v[i] = 1;
	}
	v[0] = v[n+1] = 0;
	for (int i=1;i<=n;i++) {
		if (v[i] == 1 && (v[i-1] + v[i+1] != 0)) {
			printf("No\n");
			return 0;
		}
		if (v[i] == 0 && (v[i-1] + v[i+1] == 0)) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
    return 0;
}

