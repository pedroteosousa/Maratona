#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a, b;
	for (int i=0;i<=n;i++) {
		if (i%2 == 0) a.push_back(1);
		else a.push_back(0);

		if (i == n) break;

		if (i%2 == 0) b.push_back(1);
		else b.push_back(-1);
	}
	printf("%d\n", n);
	for (int i=0;i<=n;i++) {
		printf("%d ", a[n-i]);
	}
	printf("\n%d\n", n-1);
	for (int i=0;i<=n-1;i++) {
		printf("%d ", b[n-1-i]);
	}
	printf("\n");
    return 0;
}

