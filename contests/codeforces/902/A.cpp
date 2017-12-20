#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int start = 0;
	for (int i=0;i<n;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (start < a) {
			printf("NO\n");
			return 0;
		}
		start = max(start, b);
		if (start >= m) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
    return 0;
}

