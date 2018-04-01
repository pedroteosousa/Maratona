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
	int v[20] = {1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0};
 	printf("%d\n", v[n-1]);
	return 0;
}

