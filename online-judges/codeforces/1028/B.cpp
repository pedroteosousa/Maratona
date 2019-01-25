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
	int n, m; scanf("%d %d", &n, &m);
	int k = (n+3)/4;
	for (int i=0;i<k;i++) {
		printf("5");
	} printf("\n");
	for (int i=1;i<k;i++) {
		printf("4");
	} printf("5\n");
    return 0;
}

