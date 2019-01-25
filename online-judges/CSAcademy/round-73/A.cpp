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
	int n; scanf("%d", &n);	
	int cost[5];
	cost[0] = cost[1] = cost[2] = 0;
	for (int i=0;i<n;i++) {
		int a; scanf("%d", &a);
		for (int j=0;j<3;j++) {
			int b = a;
			while (b != j) {
				b = (b+1)%3;
				cost[j]++;
			}
		}
	}
	printf("%d\n", min({cost[0], cost[1], cost[2]}));
    return 0;
}

