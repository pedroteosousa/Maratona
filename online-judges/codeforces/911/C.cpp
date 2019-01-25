#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int t[N];

int main() {
	int k1, k2, k3;
	scanf("%d %d %d", &k1, &k2, &k3);
	t[k1]++; t[k2]++; t[k3]++;
	if (t[1]) printf("YES\n");
	else if (t[2] >= 2) printf("YES\n");
	else if (t[3] == 3) printf("YES\n");
	else if (t[2] == 1 && t[4] == 2) printf("YES\n");
	else printf("NO\n");
    return 0;
}

