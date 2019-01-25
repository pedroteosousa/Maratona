#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int f(int i) {
	if (i == 1) return 1;
	else return f(i-1) + 12*(i-1);
}

int main() {
	int n; scanf("%d", &n);
	printf("%d\n", f(n));
    return 0;
}

