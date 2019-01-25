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
	int k = 0;
	if (n % 2) {
		k += (n+1)/2;
	}
	n = n/2;
	printf("%d\n", (n*(n+1)) + k);
    return 0;
}

