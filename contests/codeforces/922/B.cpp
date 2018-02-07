#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	int n; scanf("%d", &n);
	int count = 0;
	for (int i=1;i<=n;i++) {
		for (int j=i; j<=n; j++) {
			int k = i^j;
			if (k < j || k > n) continue;
			if (i+j > k && i+k > j && k+j > i) {
				count++;
			}
		}
	}
	printf("%d\n", count);
    return 0;
}

